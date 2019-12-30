#define MAX_SIZE 100
double *my_malloc(int size);
double my_average(double *start, double *end);
int delete(double **array, int *size, double average);
double max_el(double *array, double *start, double *end);
int insert(double **array, int *size, double max_elem, int p, int new_size);
