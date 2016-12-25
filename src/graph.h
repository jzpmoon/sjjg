#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph{
	char** node;
	int* matrix;
	int size;
} graph;

graph* graph_new();

#endif