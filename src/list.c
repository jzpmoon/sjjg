#include "list.h"
#include <stdlib.h>
list* list_insert(list* ls, void* data, int idx)
{
	list* pre_nd=NULL;
	list* new_nd=NULL;
	list* _ls = ls;
	int i = 0;
	while (i < idx&&_ls) {
		pre_nd = _ls;
		_ls = _ls->next;
		i++;
	}
	new_nd=(list*)malloc(sizeof(list));
	if (!new_nd) return ls;
	new_nd->data = data;
	if (pre_nd) {
		new_nd->next=pre_nd->next;
		pre_nd->next = new_nd;
		return ls;
	} else {
		new_nd->next = ls;
		return new_nd;
	}
}

void* list_query(list* ls, int idx)
{
	list* _ls = ls;
	int i = 0;
	while (i < idx&&_ls) {
		_ls = _ls->next;
		i++;
	}
	if (_ls)
		return _ls->data;
	else
		return NULL;
}