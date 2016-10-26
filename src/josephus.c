#include "clist.h"
#include <stdio.h>
list* clist_josephus(list* ls,int n,int m)
{
	list* _ls = ls;
	list* josephus_ls_head = NULL;
	list* josephus_ls_tail = NULL;
	int i = n;
	if (!ls) return NULL;
	while (i) {
		int j = 0;
		while (j < m-1+i-1) {
			_ls = _ls->next;
			j++;
		}
		if (i == n) {
			josephus_ls_head = _ls->next;
			josephus_ls_tail = _ls->next;
		}
		else {
			josephus_ls_tail->next = _ls->next;
			josephus_ls_tail = josephus_ls_tail->next;
		}
		printf("%s\n", (char*)_ls->next->data);
		_ls->next = _ls->next->next;
		_ls = _ls->next;
		i--;
	}
	if(josephus_ls_head)
		ls = josephus_ls_head;
	if(josephus_ls_tail)
		josephus_ls_tail->next = josephus_ls_head;
	return ls;
}