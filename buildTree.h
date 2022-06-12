/*
 * Project 0 -  Binary search tree 
 * buildTree.h
 * Tan Nguyen
 * ntnhmc@umsystem.edu
 * Feb 13, 2022
 */

#ifndef BUILDTREE_H
#define BUILDTREE_H
#include <stdio.h>
#include "node.h"

typedef struct {
  Node *root;
} Tree;

Node* buildTree(FILE *);
void createNode(Tree *, FILE *);
void insert(Node *, Tree *);
void insert2(Node *, Node *);
void visitNode(Node *, int, FILE *);


#endif
