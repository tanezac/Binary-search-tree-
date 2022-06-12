/*
 * Project 0 - Binary search tree 
 * traversals.c
 * Tan Nguyen
 * ntnhmc@umsystem.edu
 * Feb 13, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "traversals.h"
#include "buildTree.h"

// Traverse inorder function
void traverseInorder(Node *n, const char fileName[]) {

	const char fileExt[] = ".inorder";
    	char outFile[strlen(fileName) + strlen(fileExt)];
    	strcpy(outFile, fileName);
    	strcat(outFile, fileExt);

    	FILE *outFilePtr = fopen(outFile, "w");
    	if (!outFilePtr) {
        	printf("error: file %s could not be opened", outFile);
        	exit(1);
    	}
    	printInorder(n, 0, outFilePtr);
    	fclose(outFilePtr);
}

// Traverse preorder function
void traversePreorder(Node *n, const char fileName[]) {

    	const char fileExt[] = ".preorder";
   	char outFile[strlen(fileName) + strlen(fileExt)];
   	strcpy(outFile, fileName);
    	strcat(outFile, fileExt);

    	FILE *outFilePtr = fopen(outFile, "w");
    	if (!outFilePtr) {
        	printf("error: file %s could not be opened", outFile);
        	exit(1);
    	}
    	printPreorder(n, 0, outFilePtr);
    	fclose(outFilePtr);
}

// Traverse postorder function
void traversePostorder(Node *n, const char fileName[]) {

    	const char fileExt[] = ".postorder";
    	char outFile[strlen(fileName) + strlen(fileExt)];
    	strcpy(outFile, fileName);
    	strcat(outFile, fileExt);

    	FILE *outFilePtr = fopen(outFile, "w");
    	if (!outFilePtr) {
        	printf("error: file %s could not be opened", outFile);
        	exit(1);
    	}
    	printPostorder(n, 0, outFilePtr);
    	fclose(outFilePtr);
}

// Print inorder traversal & depth to .txt file 
void printInorder(Node *n, int depth, FILE *outFilePtr) {
	
	if (n != NULL) {
        	printInorder(n->left, depth + 1, outFilePtr);
        	visitNode(n, depth, outFilePtr);
        	printInorder(n->right, depth + 1, outFilePtr);
    	}
}

// Print preorder traversal & depth to .txt file
void printPreorder(Node *n, int depth, FILE *outFilePtr) {
    
	if (n != NULL) {
        	visitNode(n, depth, outFilePtr);
        	printPreorder(n->left, depth + 1, outFilePtr);
        	printPreorder(n->right, depth + 1, outFilePtr);
    	}
}

// Print postorder traversal & depth to .txt file
void printPostorder(Node *n, int depth, FILE *outFilePtr) {

    	if (n != NULL) {
       		printPostorder(n->left, depth + 1, outFilePtr);
        	printPostorder(n->right, depth + 1, outFilePtr);
        	visitNode(n, depth, outFilePtr);
    	}
}
