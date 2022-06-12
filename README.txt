/*
 * Project 0 -  Binary search tree 
 * p0.c
 * Tan Nguyen
 * ntnhmc@umsystem.edu
 * Feb 13, 2022
 */

Summary: Program will accept input from different sources, create a binary search tree based on the last character of the input data.
Traverse the tree using level-order, pre-order, and post-order traversals, and print out the results for all three traversals with specific indentations. 

I. What I have achieved in this project

1. Use suffix rules or pattern rules in Makfile

2. Invocation
	P0       // read from the keyboard until simulated keyboard EOF , then CRTL + D to end.
	P0 < filename // same as above except redirecting from filename instead of keyboard.
	P0 filename // reads from filename 
If user input of three or more strings on the command line should also generate this error message:
	p0.c: ERROR: BAD INPUT.
	Provide more than one File Name.
	Usage: P0 [filename] \n"
    Try './p0 -h' for more information.

If the file cannot be opened, the program will report an error
	
3. Command line parsing
	I add option -h: Help. It will be used to show how to run the program
	
4. Program output
	Program will output three files named filename.inorder, filename.preorder, and filename.postorder 
	Output files will have one node per line, in the order of the traversal :
		1. Each line will start with level number
		2. followed by a list of the strings 
		
	if the program ead from the keyboard until simulated keyboard EOF , 
	then Program will output three files named outFile.inorder, outFile.preorder, and outFile.postorder 
		
5. Architectural requirements
	Meet all the requirements of the project.
	
	
6. Succeed in writing binary tree and tree traversals functions

HOWEVER, I have a problem in processing the file how to get the last character and put it in the binary tree constructor.
For this reason, the results displayed in the file are not as expected. 

