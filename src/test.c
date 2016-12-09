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
	int i=0;
	list* (*func)(list*,void*,int)=list_insert;
	if(type)
		func=clist_insert;
	printf("please enter %d numbers\n", length);
	while(i<length){
		printf("the number:");
		scanf("%d",array+i);
		l=(*func)(l,array+i,i);
		i++;
	}
	return l;
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
	array=malloc(sizeof(int)*length);
	printf("#############clist reverse##############\n");
	x=input_to_list(array,length,1);
	x=clist_reverse(x);
	int i=0;
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
	printf("#############list merge##############\n");
	x=input_to_list(array1,length,0);
	y=input_to_list(array2,length,0);
	y=list_merge(x, y,cmp);
	while (i<20) {
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
	printf("#############josephus##############\n");
	x=input_to_list(array,length,1);
	x=clist_josephus(x,length,m);
	while (i<length) {
		printf(" %d ", *(int*)list_query(x, i));
		i++;
	}
	printf("\n");
	free(array);
}

void tree_test()
{
	tree* tree=tree_new(cmp);
	int i=0;
	while(i<5)
	{
		tree_insert(tree,&seq[i]);
		i++;
	}
	printf("pre order\n");
	tree_pre_order(tree);
	printf("in order\n");
	tree_in_order(tree);
	printf("post order\n");
	tree_post_order(tree);
}

int main()
{
	clist_josephus_test(10,2);
	return 0;
}
