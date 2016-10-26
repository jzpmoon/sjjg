#include <stdlib.h>
#include "clist.h"

list* clist_insert(list* ls, void* data, int idx)
{
	int i = 0;
	list* pre_ls = NULL;
	list* _ls = ls;
	list* new_ls = NULL;
	if (idx < 0) return ls;
	if (!ls&&idx == 0) {
		new_ls = list_new(data);
		if (new_ls)
			new_ls->next = new_ls;
		return new_ls;
	}
	while (i < idx) {
		pre_ls = _ls;
		_ls = _ls->next;
		i++;
	}
	if (i != idx) return ls;
	new_ls = list_new(data);
	if (!new_ls) return ls;
	if (pre_ls) {
		new_ls->next = pre_ls->next;
		pre_ls->next = new_ls;
	}
	else {
		new_ls->next = ls->next;
		ls->next = new_ls;
	}
	return ls;
}

void* clist_query(list* ls, int idx)
{
	list* _ls = ls;
	int i = 0;
	if (idx < 0) return NULL;
	if (!ls) return NULL;
	while (i<idx) {
		if(_ls->next != ls)
		_ls = _ls->next;
		i++;
	}
	if (idx != i)return NULL;
	return _ls->data;
}