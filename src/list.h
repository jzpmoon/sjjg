#ifndef LIST_H
#define LIST_H
#include "type.h"
typedef int(*compare_func)(void* max,void* min);
typedef struct _list list;
struct _list {
	void* data;
	struct _list* next;
};
list* list_new(void* data);
list* list_insert(list* ls, void* data, int idx);
void* list_query(list* ls, int idx);
list* list_merge(list* x, list* y,compare_func cmp);

#endif // !LIST_H
