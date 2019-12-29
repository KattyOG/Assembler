#include "tree.h"

node_struct* find_node(node_struct *head, int key, int *count)
{
    while (head != NULL)
    {
        if (head->field > key)
        {
            head = head->left;
            (*count)++;
        }
        else if (head->field < key)
        {
            head = head->right;
            (*count)++;
        }
        else if(head->field == key) {
            (*count)++;
            break;
        }
    }
    return head;
}

void inorder(node_struct *p)
{
    if (p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->field);
        inorder(p->right);
    }
}

void preorder(node_struct *p)
{
    if (p!=NULL)
    {
        printf("%d ",p->field);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node_struct *p)
{
    if (p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->field);
    }
}
node_struct* add_node(node_struct *head, node_struct *new_node, int type) //avl - 1; ddp - 0
{
    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        if (head->field >= new_node->field)
        {
            head->left = add_node(head->left, new_node, type);
        }
        else
        {
            head->right = add_node(head->right, new_node, type);
        }
    }
    if(type)
        return balance(head);
    else
        return head;
}

node_struct *create_node(int elem)
{
    node_struct *temp;
    temp = (node_struct*)malloc(sizeof(node_struct));
    temp->field = elem;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//node_struct* findmin(node_struct* p)
//{
//    return p->left?findmin(p->left):p;
//}

//node_struct* removemin(node_struct* p)
//{
//    if( p->left==0 )
//        return p->right;
//    p->left = removemin(p->left);
//    return balance(p);
//}
//node_struct* remove_node(node_struct* p, int k, int key)//avl - 1; ddp - 0
//{
//    if(!p) return 0;
//    if( k < p->field )
//        p->left = remove_node(p->left,k, key);
//    else if( k > p->field )
//        p->right = remove_node(p->right,k, key);
//    else //  k == p->key
//    {
//        node_struct* q = p->left;
//        node_struct* r = p->right;
//        free(p);
//        if( !r ) return q;
//        node_struct* min = findmin(r);
//        min->right = removemin(r);
//        min->left = q;
//        return balance(min);
//    }
//    if (key)
//        return balance(p);
//    else
//        return p;
//}

//int pop_node(node_struct **head, int elem)
//{
//    node_struct *temp = *head;
//    node_struct *prev = NULL;
//    int value = -1;
//    while (temp->field != elem)
//    {
//        if (elem > (*head)->field)
//        {
//            prev = temp;
//            temp = temp->right;
//        }
//        else
//        {
//            prev = temp;
//            temp = temp->left;
//        }
//    }
//    if (temp == *head) {
//        add_node(&((*head)->left), (*head)->right);
//        *head = (*head)->left;
//    }
//    else if (prev->right == temp) {
//        prev->right = NULL;
//        add_node(head, temp->right);
//        add_node(head, temp->left);
//    }
//    else if (prev->left == temp) {
//        prev->left = NULL;
//        add_node(head, temp->right);
//        add_node(head, temp->left);
//    }
//    value = temp->field;
//    free(temp);
//    return value;
//}

void walk_req(node_struct *head, FILE *f, node_struct* pointer)
{
    if (head == pointer && pointer != NULL)
    {
        fprintf(f, "%d [fillcolor=red, style=filled];\n", head->field);
    }
    else
        fprintf(f, "%d;\n", head->field);
    if (head->left)
    {
        fprintf(f, "%d -- %d;\n", head->field, head->left->field);
        walk_req(head->left, f, pointer);
    }
    if(head->right)
    {
        fprintf(f, "%d -- %d;\n", head->field, head->right->field);
        walk_req(head->right, f, pointer);
    }
}

void walk_tree(node_struct *head, node_struct* pointer)
{
    FILE* f = fopen("input.dot", "w");
    fprintf(f, "graph \"\"\n");
    fprintf(f, "{\n");
    walk_req(head, f, pointer);
    fprintf(f, "}\n");
    fclose(f);
    system("dot -Tpng input.dot > output.png");
    system("xviewer output.png &");

}

void free_tree(node_struct *head)
{
    if (head->left)
    {
        free_tree(head->left);
    }
    if(head->right)
    {
        free_tree(head->right);
    }
    free(head);
}

node_struct* rotateright(node_struct* p)
{
    node_struct* q = p->left;
    p->left = q->right;
    q->right = p;
    return q;
}

node_struct* rotateleft(node_struct* q)
{
    node_struct* p = q->right;
    q->right = p->left;
    p->left = q;
    return p;
}

int bfactor(node_struct* head)
{
    if(head == NULL)
        return 0;
    int left, right;
    if (head->left != NULL) {
        left = bfactor(head->left);
    }
    else
        left = 0;
    if (head->right != NULL) {
        right = bfactor(head->right);
    }
    else
        right = 0;
    int max = left > right ? left : right;
    return max + 1;
}

node_struct* balance(node_struct* p)
{
    if((bfactor(p->right) - bfactor(p->left))== 2)
    {
        if((bfactor(p->right->right) - bfactor(p->right->left)) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if((bfactor(p->right) - bfactor(p->left))==-2)
    {
        if((bfactor(p->left->right) - bfactor(p->left->left)) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}
