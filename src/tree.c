#include <stdlib.h>
#include "tree.h"

tree* tree_new(compare_func* cmp)
{
	tree* tree=malloc(siezof(tree));
	tree->root=NULL;
	tree->cmp=cmp;
	return tree;
}
struct _tree_nd* tree_nd_new(void* data)
{
	struct _tree_nd* nd=malloc(sizeof(struct _tree_nd));
	nd->data=NULL;
	nd->left=NULL;
	nd->right=NULL;
	return nd;
}
void tree_insert(tree* tree,void* data)
{
	struct _tree_nd* pre_nd=NULL;
	struct _tree_nd* nd=NULL;
	int i=0;c=0;
	if(!tree) return;
	compare_func* cmp=tree->cmp;
	nd=tree->root;
	while(nd)
	{
		c=cmp(data,nd->data);
		pre_nd=nd;
		if(c==1)
		{
			nd=nd->left;
		}else if(c==-1)
		{
			nd=nd->right;
		}else
		{
			return;
		}
	}
	struct _tree_nd* new_nd=tree_nd_new(data);
	c=cmp(data,pre_nd->data);
	if(c==1)
	{
		pre_nd->left=new_nd;
	}else
	{
		pre_nd->right=new_nd;
	}
	return;
}