#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree* tree_new(compare_func cmp)
{
	tree* tree=malloc(sizeof(tree));
	tree->root=NULL;
	tree->cmp=cmp;
	return tree;
}
struct _tree_nd* tree_nd_new(void* data)
{
	struct _tree_nd* nd=malloc(sizeof(struct _tree_nd));
	nd->data=data;
	nd->left=NULL;
	nd->right=NULL;
	return nd;
}
void tree_insert(tree* tree,void* data)
{
	struct _tree_nd* pre_nd=NULL;
	struct _tree_nd* nd=NULL;
	struct _tree_nd* new_nd=NULL;
	compare_func cmp=NULL;
	int i=0,c=0;
	if(!tree) return;
	cmp=tree->cmp;
	nd=tree->root;
	while(nd)
	{
		c=cmp(data,nd->data);
		pre_nd=nd;
		if(c==1)
		{
			nd=nd->right;
		}else if(c==-1)
		{
			nd=nd->left;
		}else
		{
			return;
		}
	}
	new_nd=tree_nd_new(data);
	if(!pre_nd)
	{
		tree->root=new_nd;
		return;
	}
	c=cmp(data,pre_nd->data);
	if(c==1)
	{
		pre_nd->right=new_nd;
	}else
	{
		pre_nd->left=new_nd;
	}
	return;
}

void tree_pre_order(tree* tree)
{
	struct _tree_nd* nd=NULL;
	int top=-1;
	void* stack[1000];
	if(!tree) return;
	nd=tree->root;
	while(1){
		if(nd){
			printf("node data:%d\n",*(int*)nd->data);
			if(nd->right)
				stack[++top]=nd->right;
			nd=nd->left;
		}else{
			if(top==-1) break;
			nd=stack[top--];
		}
	}
	return;
}
void tree_in_order(tree* tree)
{
	struct _tree_nd* nd=NULL;
	int top=-1;
	void* stack[1000];
	if(!tree) return;
	nd=tree->root;
	while(1){
		if(nd){
			stack[++top]=nd;
			nd=nd->left;
		}else{
			if(top==-1) break;
			nd=stack[top--];
			printf("node data:%d\n",*(int*)nd->data);
			nd=nd->right;
		}
	}
	return;
}

void tree_post_order(tree* tree)
{
	struct _tree_nd* pre_nd=NULL;
	struct _tree_nd* nd=NULL;
	int top=-1;
	void* stack[1000];
	if(!tree) return;
	nd=tree->root;
	while(1){
		if(nd){
			stack[++top]=nd;
			nd=nd->left;
		}else{
			if(top==-1) break;
				nd=stack[top--];
			if(!nd->left&&!nd->right || nd->left&&!nd->right&&nd->left==pre_nd || nd->right&&nd->right==pre_nd){
				printf("node data:%d\n",*(int*)nd->data);
				pre_nd=nd;
				if(top==-1) break;
					nd=stack[top--];
			}else{
				stack[++top]=nd;
				nd=nd->right;
			}
		}
	}
	return;
}