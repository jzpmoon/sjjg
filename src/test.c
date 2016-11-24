#include "clist.h"
#include <stdio.h>
#include <windows.h>
int seq[] = { 1,2,3,4,5 };

int cmp(void* max, void* min)
{
	if (*(int*)max > *(int*)min) {
		return 1;
	}
	else if(*(int*)max < *(int*)min)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void list_test()
{
	list* x = NULL;
	list* y = NULL;
	int i = 0; int j = 0;
	while (i < 5) {
		x = list_insert(x, &seq[i], i);
		y = list_insert(y, &seq[i], i);
		i++;
	}
	y=list_merge(x, y,cmp);
	while (j<10) {
		int* data = NULL;
		data=list_query(y, j);
		printf("data:%d\n", *data);
		j++;
	}
	Sleep(5000);
}

void tree_test()
{
	tree* tree=tree_new(cmp);
	tree_insert(seq[]);
}