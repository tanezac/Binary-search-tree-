# Binary-search-tree-
Program will accept input from different sources, create a binary search tree based on the  last character of the input data, traverse the tree using level-order, pre-order, and post-order traversals,  and print out the results for all three traversals with specific indentations. 
Objective: Programming refreshment, practice with standards and header files, practice with trees, 
traversals, string manipulations, and file IO. Program must be written in C/C++ and compile and run on 
clark.rnet.missouri.edu. 
Summary: Program will accept input from different sources, create a binary search tree based on the 
last character of the input data, traverse the tree using level-order, pre-order, and post-order traversals, 
and print out the results for all three traversals with specific indentations. 
Invocation:  
P0 [filename] 
where filename is an optional argument. If a file name is given, the program will read from the file. 
Otherwise it will read from the keyboard until simulated keyboard EOF (Ctrl + D).  
• P0       // read from the keyboard until simulated keyboard EOF 
• P0 < filename // same as above except redirecting from filename instead of keyboard (no 
extra code needed) 
• P0 filename // reads from filename 
If none of the three options are provided by the user an appropriate error message is given and usage is 
specified. Note that user input of three or more strings on the command line should also generate this 
error message. For example: 
P0 file1 file2     // command line arguments provided by user 
Fatal: Improper usage    // example error message with usage specified 
Usage: P0 [filename] 
Input data: 
Assume you do not know the size of the input file. Check that input data is all lowercase character 
strings without any numbers or special characters. Assume the strings are separated with any number of 
standard white-space separators (space, tab, newline).  
If an unallowed string is encountered, program needs to abort with an appropriate error message.  
Program function: 
• Program will read in character strings and put them into a binary search tree (BST) with respect 
to the LAST character of the string.  
• Each node in the tree will contain: 
o The LAST character of the string 
o Two child nodes (left and right) 
o A list of the strings already seen that END with the same character as the node’s 
character 
• Tree is never balanced nor restructured other than growing new nodes 
Program output: 
• Program will output three files named filename.levelorder, filename.preorder, and 
filename.postorder 
o The first half of the filename must match the input filename or ‘out’ for keyboard entry 
(for P0 usage or P0 < filename usage) 
• Output files will have one node per line, in the order of the traversal 
o Each line will be indented by 2 x the depth of the node (in number of blank spaces) 
o Each line will start with level number, followed by LAST character, followed by a list of 
the strings seen that begin with the same LAST character in the order in which they 
appeared (each of the printed strings need to be separated by a single space) 
Architectural requirements: 
• Have the following functions minimum in addition to the main function (the types and 
arguments are just suggested, the names are required) 
node_t *buildTree(FILE *);  
void traverseLevelOrder(node_t*, const char[]);           
// parameters: tree root, and output basefilename 
void traversePreOrder(node_t*, const char[]); 
void traversePostOrder(node_t*, const char[]); 
 
• Put the above four functions into 2 files with proper headers (buildTree.h and 
traversals.h)  
• Define the node type in node.h 
• Be sure to use this functional architecture 
 
Suggestions: 
Our illustrations and discussions will use pseudocode or C/C++ as the programming language. We will 
approach the project from functional modularization point of view, so preferable design is functional, 
and implementation in C or C++ is required.  
Traversals can be reviewed in Cmp Sci 3130 textbook. Briefly: 
• Level-order processes each node from left to right in each level, from top to bottom  
• Pre-order processes root, followed by left child, followed by right child 
• Post-order processes left child, followed by right child, followed by root 
Using top-down decomposition you have 3 tasks in main: 
1. Process command arguments, set up file to process regardless of source, check if file is 
readable, set the basename for the output file, etc. 
2. Build the tree 
3. Traverse the tree using three different ways of generating outputs 
 
The main function must handle the 3 functionalities. #1 should be handled inside of main, 
functions for #2 should be in a separate source, and functions for #3 should be in another 
separate source. Any node types should be defined in a separate header file.    
 
For development purposes, do either 1 or 2 first. 3 should follow 2, first with one traversal only. 
 
Processing keyboard input can be done in either of the following ways: 
1. Read the input into a temporary file, after which the rest of the program always 
processes file input, the same as for file input 
2. Set file pointer to stdin, then process always from the file pointer 
 
Suggested files:  
• Makefile (first part) 
o CC = g++ 
o CFLAGS = -g -Wall -std=c++11 
o OBJS = main.o buildTree.o traversals.o  
o TARGET = P0 
• node.h, main.c, traversals.c, traversals.h, buildTree.c and 
buildTree.h 
• main.c  
o #include "node.h" 
#include "traversals.h" 
#include "buildTree.h" 
 
int main(int argc, char* argv[]) { 
  // process command line arguments and make sure file    
  is readable, error otherwise 
  // set up keyboard processing so that below the  
  input method is not relevant 
 
  node_t *root = buildTree(file); 
 
  levelOrder(root); 
  preOrder(root); 
  postOrder(root); 
 
  return 0; 
} 
 
A sample function for printing tree: 
static void printParseTree(nodeType *rootP, int level) { 
  if (rootP == NULL) return; 
  printf("%*c%d:%s ",level*2,' ',level,NodeId.info); // assume 
some info printed as string 
  printf("\n"); 
  printParseTree(rootP->child1,level+1); 
  printParseTree(rootP->child2,level+1); 
} 
 
Note that “%*c”, length, char prints length-1 spaces followed by char.  
Suggested initial testing (you need to add further tests so that all functionality is tested): 
1. Create test files:  
1. P0_test1 containing empty file 
2. P0_test2 containing one string: abcd 
3. P0_test3 containing some strings with same LAST characters and different across 
same line and multiple lines:  
abcd cold dogs 
card  carts zoo 
4. P0_test4 with different ordering of LAST characters to test BST construction: 
lion zebra eagle dove leopard 
ant monkey zoo turkey 
5. P0_test5 with input errors: 
lioN   // edit to test other input errors 
 
2. For each test file, draw by hand the tree that should be generated. For example, 
P0_test2 should create just one node 'd' with one string ‘abcd’ 
3. Decide on invocations and what should happen, what should be output filenames if no 
error, and what the output files should look like - using the hand drawn trees for each 
file 
4. Run the invocations and check against predictions  
1. $ P0 < P0_test1 
Error 
 
2. $ P0 < P0_test3 
Outputs out.levelorder out.preorder out.postorder, each containing  
the original strings in the correct order and with correct indentations. For 
example:  
       0 d abcd cold  
  1 s dogs carts 
    2 o zoo 
 
3. $ P0 P0_test3 
Outputs P0_test3.levelorder, P0_test3.preorder, and P0_test3.postorder 
containing as above 
 
