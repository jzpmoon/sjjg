#include "clist.h"
#include <stdlib.h>

list* list_insert(list* ls, void* data, int idx)
{
	int i = 0;
	list* _ls = ls;
	list* pre_ls = NULL;
	list* new_ls=NULL;
	if (idx < 0) return ls;
	if (!ls&&idx == 0) {
		ls = list_new(data);
		return ls;
	}
	while (i < idx&&_ls)
	{
		pre_ls = _ls;
		_ls = _ls->next;
		i++;
	}
	if (i != idx) return ls;
	new_ls = list_new(data);
	if (!new_ls) return ls;
	if (pre_ls) {
		new_ls->next=pre_ls->next;
		pre_ls->next = new_ls;
	}
	else {
		new_ls->next = ls->next;
		ls->next = new_ls;
	}
	return ls;
}
void* list_query(list* ls, int idx)
{
	list* _ls = ls;
	int i = 0;
	if (idx < 0) return NULL;
	if (!ls) return NULL;
	while (i < idx&&_ls)
	{
		_ls = _ls->next;
		i++;
	}
	if (_ls)
		return _ls->data;
	else
		return NULL;
}
