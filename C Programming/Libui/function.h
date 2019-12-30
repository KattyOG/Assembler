#define MAX_SIZE 100
#include "ui.h"

double *my_malloc(int size);
double my_average(double *start, double *end);
int delete(double **array, int *size, double average);
double max_el(double *array, double *start, double *end);
int insert(double **array, int *size, double max_elem, int p, int new_size);


uiBox *vbox;
uiBox *hbox;
uiGroup *group;
uiGroup *new_group;
uiForm *entryForm;
uiForm *new_entryForm;
uiCombobox *cbox;
uiButton *button;
uiEntry *entry;
uiGrid *grid;
uiBox *b;
uiWindow *w;
uiButton *btn;
uiEntry* size;
uiEntry* string;
double *array;
int int_size;
int p;
uiEntry* p_input;
