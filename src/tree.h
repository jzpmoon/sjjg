#ifndef TREE_H
#define TREE_H
#include "type.h"
typedef struct _tree tree;
struct _tree_nd
{
	void* data;
	struct _tree_nd* left;
	struct _tree_nd* right;
}
struct _tree
{
	struct _tree_nd* root;
	compare_func* cmp;
}

tree* tree_new(compare_func* cmp);
void tree_insert(tree* tree,void* data);
void tree_pre_order(tree* tree);

#endif
