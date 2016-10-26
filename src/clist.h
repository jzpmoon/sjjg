#include "list.h"

list* clist_insert(list* ls, void* data, int idx);
void* clist_query(list* ls, int idx);
list* clist_josephus(list* ls, int n, int m);
list* clist_reverse(list* ls);