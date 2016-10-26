#include "list.h"
#include <stdlib.h>

list* list_new(void* data)
{
	list* ls = (list*)malloc(sizeof(list));
	if (ls){
		ls->data = data;
		ls->next = NULL;
	}
	return ls;
}