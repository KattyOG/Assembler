struct matrix_struct
{
	int row;
	int column;
	long long **ptr;
} typedef matrix;
int init_matrix(matrix *my_matrix);
void free_matrix(matrix *my_matrix);
void print_matrix(matrix my_matrix);
void delete_row(matrix *my_matrix, int num_row);
void delete_column(matrix *my_matrix, int num_column);
long long int min_row(matrix *my_matrix, int num);
void add_column(matrix *my_matrix, int num_column);
int geom_average(matrix *my_matrix, int num);
void add_row(matrix *my_matrix, int num_row);
int min_in_row_i(matrix *my_matrix);
int min_in_row_j(matrix *my_matrix);
void power_matrix(matrix *my_matrix, int pow);
void multip_matrix(matrix *my_matrix, matrix *my_matrix2);
