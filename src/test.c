#include "list.h"
#include <stdio.h>
int main()
{
	list* ls = NULL;
	int i = 0;
	while (i<10) {
		ls = list_insert(ls, "hello", i);
		printf("%s\n", (char*)list_query(ls, i));
		i++;
	}
	while (1) {}
}