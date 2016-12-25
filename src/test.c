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
	printf("������ %d ������\n", length);
	while(i<=length){
		printf("��%d����:",i);
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
	printf("������ %d ������\n", length);
	while(i<=length){
		printf("��%d����:",i);
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
	printf("#############��������ת##############\n");
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
	printf("#############������ϲ�##############\n");
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
	printf("#############Լɪ������##############\n");
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
	printf("#############������##############\n");
	array=malloc(sizeof(int)*length);
	tree=input_to_tree(array,length);
	printf("�������\n");
	tree_pre_order(tree);
	printf("�������\n");
	tree_in_order(tree);
	printf("�������\n");
	tree_post_order(tree);
}

int main()
{
	int s=0,length=0;
	while(1){
		printf("1. ��дһ��ѭ�������ڼ���20�����ĳ��򣨲���ͷ�ڵ㵥����\n");
		printf("2. Լɪ������\n");
		printf("3. �ϲ�������������\n");
		printf("4. ��������ת\n");
		printf("5. ����������\n");
		printf("6. test6\n");
		printf("7. �˳�\n");
		scanf("%d",&s);
		if(s==7){
			return 0;
		}
		printf("�����빹��ڵ����Ŀ");
		scanf("%d",&length);
		if(s==1){
			list_test(length);
		}else if(s==2){
			int n=0;
			printf("Լɪ������ļ��");
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
