/*
 * Project 0 -  Binary search tree 
 * buildTree.c
 * Tan Nguyen
 * ntnhmc@umsystem.edu
 * Feb 13, 2022
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "buildTree.h"

static const int WORD_SIZE = 32;
static const int BUFFER = 1000;

// Create node within this function from file
void createNode(Tree *bst, FILE *inputFile) {

	char input[WORD_SIZE];
   	fscanf(inputFile, "%s", input);
    	Node *newNode = (Node *) malloc(sizeof(Node));
    	newNode->left = NULL;
    	newNode->right = NULL;
    	newNode->key = strlen(input);
    	strcpy(newNode->words, input);
    	insert(newNode, bst);
}

// Build binary tree
Node *buildTree(FILE *fp) {
	Tree bst = { .root = NULL };
    	while (!feof(fp)) {
        	createNode(&bst, fp);
    	}
    	return bst.root;
}

// Insert node into bst 
void insert(Node *newNode, Tree *bst) {
    	if (bst->root == NULL) {
        	bst->root = newNode;
    	}
    	else {
        	insert2(newNode, bst->root);
    	}
}

// Insert additional node from keyboard input into bst 
void insert2(Node *newNode, Node *currentNode) {
   	if (newNode->key > currentNode->key) {
        	if (currentNode->right == NULL) {
            		currentNode->right = newNode;
        	}
        	else {
            		insert2(newNode, currentNode->right);
        	}	
    	}
    	else if (newNode->key == currentNode->key) {
        	if (strstr(currentNode->words, newNode->words) == NULL) {
            		strcat(currentNode->words, " ");
            		strcat(currentNode->words, newNode->words);
        	}
    	}
   	 else {
        	if (currentNode->left == NULL) {
            		currentNode->left = newNode;
        	}
        	else {
            		insert2(newNode, currentNode->left);
        	}
    	}
}

// Print node corresponding depth spaces
void visitNode(Node *n, int depth, FILE *outFilePtr) {
    	fprintf(outFilePtr, "%*s%d %s\n", depth * 2, "", n->key, n->words);
}


