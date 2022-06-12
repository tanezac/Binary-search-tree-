/*
 * Project 0 -  Binary search tree 
 * node.h
 * Tan Nguyen
 * ntnhmc@umsystem.edu
 * Feb 13, 2022
 */


#ifndef NODE_H
#define NODE_H

typedef struct Node {
	int key;
	char words[128];
	struct Node* left;
	struct Node* right;
} Node;

#endif
