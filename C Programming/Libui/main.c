#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"
static uiWindow *mainwin;
uiMultilineEntry *e;

static int onClosing(uiWindow *w, void *data)
{
	uiQuit();
	return 1;
}

static int onShouldQuit(void *data)
{
	uiWindow *mainwin = uiWindow(data);

	uiControlDestroy(uiControl(mainwin));
	return 1;
}


void saySomething()
{
	char *str;
	int j = 0;

	if (array) {
		free(array);
		array = NULL;
	}

	int_size = atoi(uiEntryText(size));
	if (int_size < 0)
	{
		uiMsgBoxError(mainwin,
		              "Input error",
		              "");
		return;
	}
	p = atoi(uiEntryText(p_input));
	array = (double*)my_malloc(int_size);
	if (array == NULL)
		return;
	str = uiEntryText(string);
	int num_of_elem = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			j++;
		}
		else {
			array[j] = (array[j] * 10 + (str[i] - 48));
			num_of_elem++;
			if (num_of_elem > int_size)
			{
				uiMsgBoxError(mainwin,
				              "Input error",
				              "");
				return;
			}
		}
	}

	if (num_of_elem < int_size)
	{
		free(array);
		array = NULL;
		uiMsgBoxError(mainwin,
		              "Input error",
		              "");
		return;
	}

	double average = my_average(array, array + int_size);

	int temp = delete(&array, &int_size, average);
	if (temp == EXIT_FAILURE)
	{
		free(array);
		array = NULL;
		uiMsgBoxError(mainwin,
		              "Input error",
		              "");
		return;
	}
	if (int_size == 0)
	{
		free(array);
		array = NULL;

		uiMsgBoxError(mainwin,
		              "Input error",
		              "");
		return;
	}
	double max_element = max_el(array, array, array + int_size);
	temp = insert(&array, &int_size, max_element, p, 3);
	if (temp == EXIT_FAILURE)
	{
		free(array);
		array = NULL;

		uiMsgBoxError(mainwin,
		              "Input error",
		              "");
		return;
	}
	for (int i = 0; i < int_size; i++)
	{
		char temp_str[20];
		sprintf(temp_str,"%f ",array[i]);
		uiMultilineEntryAppend(e, temp_str);
	}
	uiMultilineEntryAppend(e, "\n");
	printf("\n");
	free(array);
	array = NULL;

}
static uiControl *makeBasicControlsPage(void)
{
	vbox = uiNewVerticalBox();
	uiBoxSetPadded(vbox, 1);

	hbox = uiNewHorizontalBox();
	uiBoxSetPadded(hbox, 1);
	uiBoxAppend(vbox, uiControl(hbox), 0);

	group = uiNewGroup("Input elements with a space");
	uiGroupSetMargined(group, 1);

	uiBoxAppend(vbox, uiControl(group), 0);

	entryForm = uiNewForm();
	uiFormSetPadded(entryForm, 1);
	uiGroupSetChild(group, uiControl(entryForm));

	size = uiNewEntry();
	string = uiNewEntry();
	p_input = uiNewEntry();
	uiFormAppend(entryForm,
	             "Size",
	             uiControl(size),
	             0);

	uiFormAppend(entryForm,
	             "Elements",
	             uiControl(string),
	             0);

	uiFormAppend(entryForm,
	             "P",
	             uiControl(p_input),
	             0);
	btn = uiNewButton("Input");
	uiButtonOnClicked(btn, saySomething, NULL);
	uiBoxAppend(vbox, uiControl(btn), 0);

	b = uiNewVerticalBox();
	uiBoxSetPadded(b, 1);
	e = uiNewMultilineEntry();
	uiMultilineEntrySetReadOnly(e, 1);
	uiBoxAppend(vbox, uiControl(e), 1);

	return uiControl(vbox);
}

int main(void)
{
	uiInitOptions options;
	const char *err;
	uiTab *tab;


	memset(&options, 0, sizeof (uiInitOptions));
	err = uiInit(&options);
	if (err != NULL) {
		fprintf(stderr, "error initializing libui: %s", err);
		uiFreeInitError(err);
		return 1;
	}

	mainwin = uiNewWindow("Lab 10", 1000, 800, 1);
	uiWindowOnClosing(mainwin, onClosing, NULL);
	uiOnShouldQuit(onShouldQuit, mainwin);

	tab = uiNewTab();
	uiWindowSetChild(mainwin, uiControl(tab));
	uiWindowSetMargined(mainwin, 1);

	uiTabAppend(tab, "Main window", makeBasicControlsPage());
	uiTabSetMargined(tab, 0, 1);

	uiControlShow(uiControl(mainwin));
	uiMain();
	return 0;
}
