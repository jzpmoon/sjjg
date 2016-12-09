#include <stdlib.h>
#include "list.h"

list* list_merge(list* x, list* y, compare_func cmp)
{
	list* _x = x;
	list* next_x = NULL;
	list* _y = y;
	list* pre_y = NULL;
	if (!x) return y;
	if (!y) return x;
	while (_x&&_y)
	{

		int c = (*cmp)(_x->data, _y->data);
		if (c >= 0) {
			pre_y = _y;
			_y = _y->next;
		}
		else
		{
			next_x = _x->next;
			if (pre_y) {
				_x->next = pre_y->next;
				pre_y->next = _x;
				pre_y = _x;
			}
			else
			{
				_x->next = y;
				y = _x;
				pre_y = _x;
			}
			_x = next_x;
		}
	}
	if (_x) {
		pre_y->next = _x;
	}
	return y;
}