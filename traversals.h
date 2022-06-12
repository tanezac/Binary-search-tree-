/* 
 * Project 0 - Binary search tree 
 * traversals.h
 * Tan Nguyen
 * ntnhmc@umsystem.edu
 * Feb 13, 2022
 */

#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <stdio.h>
#include "node.h"


void traverseInorder(Node *, const char []);
void traversePreorder(Node *, const char []);
void traversePostorder(Node *, const char []);
void printInorder(Node *, int, FILE *);
void printPreorder(Node *, int, FILE *);
void printPostorder(Node *, int, FILE *);

#endif
