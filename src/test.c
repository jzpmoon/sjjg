#include "clist.h"
#include "tree.h"
#include <stdio.h>
#include <windows.h>
int seq[] = { 1,2,3,4,5 };
int seq1[] = { 60,70,80,90,100 };

int cmp(void* max, void* min)
{
	if (*(int*)max > *(int*)min) {
		return 1;
	}
	else if(*(int*)max < *(int*)min)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
list* input_to_list(int array[],int length,int type)
{
	list* l=NULL;
	int i=1;
	list* (*func)(list*,void*,int)=list_insert;
	if(type)
		func=clist_insert;
	printf("请输入 %d 个数字\n", length);
	while(i<=length){
		printf("第%d个数:",i);
		scanf("%d",array+i-1);
		l=(*func)(l,array+i-1,i-1);
		i++;
	}
	return l;
}
tree* input_to_tree(int array[],int length)
{
	tree* t=tree_new(cmp);
	int i=1;
	printf("请输入 %d 个数字\n", length);
	while(i<=length){
		printf("第%d个数:",i);
		scanf("%d",array+i-1);
		tree_insert(t,array+i-1);
		i++;
	}
	return t;
}
void list_test(int length)
{
	int i=0;
	int* array=NULL;
	list* l=NULL;
	array=malloc(length*sizeof(int));
	printf("############# signed list ##############\n");
	l=input_to_list(array,length,0);
	while(i<length)
	{
		printf(" %d ",*(int*)list_query(l,i));
		i++;
	}
	printf("\n");
	free(array);
}
void clist_reverse_test(int length)
{
	list* x=NULL;
	int* array=NULL;
	int i=0;
	array=malloc(sizeof(int)*length);
	printf("#############单链表逆转##############\n");
	x=input_to_list(array,length,1);
	x=clist_reverse(x);
	while(i<length)
	{
		printf(" %d ",*(int*)clist_query(x,i));
		i++;
	}
	printf("\n");
	free(array);
}
void list_merge_test(int length)
{
	list* x = NULL;
	list* y = NULL;
	int i=0;
	int* array1=NULL;
	int* array2=NULL;
	array1=malloc(sizeof(int)*length);
	array2=malloc(sizeof(int)*length);
	printf("#############单链表合并##############\n");
	x=input_to_list(array1,length,0);
	y=input_to_list(array2,length,0);
	y=list_merge(x, y,cmp);
	while (i<length*2) {
		printf(" %d ", *(int*)list_query(y, i));
		i++;
	}
	printf("\n");
	free(array1);
	free(array2);
}

void clist_josephus_test(int length,int m)
{
	list* x=NULL;
	int* array=NULL;
	int i=0;
	array=malloc(sizeof(int)*length);
	printf("#############约瑟夫问题##############\n");
	x=input_to_list(array,length,1);
	x=clist_josephus(x,length,m);
	while (i<length) {
		printf(" %d ", *(int*)list_query(x, i));
		i++;
	}
	printf("\n");
	free(array);
}

void tree_test(int length)
{
	int* array=NULL;
	tree* tree=NULL;
	printf("#############二叉树##############\n");
	array=malloc(sizeof(int)*length);
	tree=input_to_tree(array,length);
	printf("先序遍历\n");
	tree_pre_order(tree);
	printf("中序遍历\n");
	tree_in_order(tree);
	printf("后序遍历\n");
	tree_post_order(tree);
}

int main()
{
	int s=0,length=0;
	while(1){
		printf("1. 编写一个循环不少于己于20行语句的程序（不带头节点单链表）\n");
		printf("2. 约瑟夫问题\n");
		printf("3. 合并两个有序链表\n");
		printf("4. 单链表逆转\n");
		printf("5. 二叉树遍历\n");
		printf("6. test6\n");
		printf("7. 退出\n");
		scanf("%d",&s);
		if(s==7){
			return 0;
		}
		printf("请输入构造节点的数目");
		scanf("%d",&length);
		if(s==1){
			list_test(length);
		}else if(s==2){
			int n=0;
			printf("约瑟夫问题的间隔");
			scanf("%d",&n);
			clist_josephus_test(length,2);
		}else if(s==3){
			list_merge_test(length);
		}else if(s==4){
			clist_reverse_test(length);
		}else if(s==5){
			tree_test(length);
		}else if(s==6){

		}
	}
}
