#ifndef BST_H
#define BST_H

#include <stdlib.h>

typedef struct Node {
    unsigned char char_data;
    struct Node *left;
    struct Node *right;
} Node;

Node *initializeNode_Empty();
Node *initializeNode_Char(unsigned char c);

Node *insertNodeRoot(Node *n, unsigned char c);
int insertNode(unsigned char c);
int compareNodes(unsigned char L, unsigned char R);

Node *searchNode(unsigned char c);

int removeNode(unsigned char c);
Node *removeNodeRoot(Node *root, unsigned char c);

void display_tree(Node *n);
void printTree();

void printNDepth(Node *n, int want, int at);

void printElementsAtDepthUTIL(Node *n, int want, int at);
void printElementsAtDepth(int user);

void numberLeafs();
unsigned int countLeafs(Node *n);

void Done();
void cleanTree(Node *n);
#endif
