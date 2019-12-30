struct my_list
{
	int value[3];
	struct my_list *next;
} typedef list;

void insert_list(list *(*head), int i, int j, int val);
int max_size(list *head, int *size);
void print_matrix(list **head, int size_i, int size_j);
void delete_row(list **head);
void sum_matrix(list **head, list **head2, list **head3);
list *find_in_list(list *head, int row, int column);
list *multip_matrix(list *head, list *head2);
void free_matrix(list **head);
