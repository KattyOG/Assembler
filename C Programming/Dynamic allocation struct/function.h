struct set_goods
{
	char *article;
	char *name;
	unsigned int *quantity;
} typedef goods;
int malloc_for_module(goods **new_goods, int size);
int my_scanf(char *buf_article, char *buf_name, unsigned int *buf_quantity);
int creat_field(goods **new_goods, int num, char *buf_article, char *buf_name, unsigned int buf_quantity);
void free_field(goods **new_goods, int size);
void delete(goods **new_goods, int *size);
void add_name(goods **new_goods, int size);
void sort(int size, goods **new_goods, int compare(goods, goods));
int compare_article(goods first, goods second);
int compare_name(goods first, goods second);
int compare_quantity(goods first, goods second);
int key(goods *new_goods, int size);
