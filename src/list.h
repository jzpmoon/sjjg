#ifndef LIST_H
#define LIST_H

typedef struct _list list;
struct _list {
	void* data;
	struct _list* next;
};
list* list_insert(list* ls, void* data, int idx);
void* list_query(list* ls, int idx);

#endif // !LIST_H