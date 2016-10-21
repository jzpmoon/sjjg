#include "list.h"
#include <stdlib.h>
static list* list_new(void* data)
{
	list* ls = (list*)malloc(sizeof(list));
	if (ls)
		ls->data = data;
	return ls;
}
list* list_insert(list* ls, void* data, int idx)
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
	while (i < idx&&_ls) {
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

void* list_query(list* ls, int idx)
{
	if (idx < 0) return NULL;
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