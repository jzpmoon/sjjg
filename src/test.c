#include "clist.h"
#include <stdio.h>
#include <windows.h>
char* seq[] = { "1","2","3","4","5" };

int cmp(void* max, void* min)
{
	if ((char)max > (char)min) {
		return 1;
	}
	else if((char)max < (char)min)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	list* x = NULL;
	list* y = NULL;
	int i = 0; int j = 0;
	while (i < 5) {
		x = list_insert(x, seq[i], i);
		y = list_insert(y, seq[i], i);
		i++;
	}
	y=list_merge(x, y,cmp);
	while (j<10) {
		char* data = NULL;
		data=list_query(y, j);
		printf("data:%s\n", data);
		j++;
	}
	Sleep(5000);
}