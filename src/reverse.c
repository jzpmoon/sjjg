#include <stdlib.h>
#include "clist.h"

list* clist_reverse(list* ls)
{
	list* pre = NULL;
	list* nd = NULL;
	list* next = NULL;
	if (!ls) return NULL;
	nd = ls;
	if (!ls->next) {
		return ls;
	}
	else {
		next = ls->next;
	}
	while (1)
	{
		nd->next = pre;
		if (next->next!=ls) {
			pre = nd;
			nd = next;
			next = next->next;
		}
		else {
			next->next = nd;
			ls->next = next;
			ls = next;
			return ls;
		}
	}
}