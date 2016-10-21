#include "list.h"
#include <stdio.h>
#include <windows.h>
int main()
{
	list* ls = NULL;
	list* josephus_ls = NULL;
	int i = 0; int j = 0;
	char* seq[] = {"1","2","3","4","5"};
	while (i<5) {
		ls = list_insert(ls, seq[i], i);
		i++;
	}
	josephus_ls=josephus(ls, 5, 0);
	Sleep(5000);
}