#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node *root = NULL;

Node *initializeNode_Empty() {
    Node* node = malloc(sizeof(*node));
    if (node != NULL) {
        node->char_data = '\0';
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

Node *initializeNode_Char(unsigned char c) {
    Node *node = malloc(sizeof(*node));
    if (node != NULL) {
        node->char_data = c;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

int compareNodes(unsigned char L, unsigned char R) {
    if (R > L) {
        return 1;
    }
    else if (L > R) {
        return -1;
    }
    else if (L == R) {
        return 0;
    }
}

int insertNode(unsigned char c) {
    if (root == NULL) {
        printf("\nAttempting to make new root %c...", c);
        Node *n = initializeNode_Empty();
        printf(" Root made succesfully!\n");
        root = initializeNode_Char(c);
    }
    else {
        printf("\nAttempting to make Node %c...", c);
        insertNodeRoot(root, c);
        printf(" Node made succesfully!");
    }
}

Node *insertNodeRoot(Node *n, unsigned char c) {
    Node *itr = root;
    Node *parent = NULL;

    int move_left, move_right = 0;

    while (itr != NULL) {

        move_right = compareNodes(c, itr->char_data);
        parent = itr;

        switch (move_right) {
            case 0:
            case -1: {
                move_left = 0;
                itr = itr->right;
                break;
            }
            case 1: {
                move_left = 1;
                itr = itr->left;
                break;
            }
        }// end of switch
    }// end of iterator

    if (move_left) {
        parent->left = initializeNode_Char(c);
    }
    else {
        parent->right = initializeNode_Char(c);
    }

    return root;
}

Node *searchNode(unsigned char c) {
    if (root == NULL) {
        return NULL;
    }
    printf("\nSearching for %c...", c);
    int move_right;
    Node *itr = root;
    while (itr != NULL) {
        move_right = compareNodes(c, itr->char_data);
        switch (move_right) {
            case -1: {
                itr = itr->right;
                break;
            }
            case 0: {
                printf(" Found %c.", c);
                return itr;
            }
            case 1: {
                itr = itr->left;
                break;
            }
        } // end switch
    } // end iterator loop

    return itr;
}

Node *removeNodeRoot(Node *root, unsigned char c) {
    //printf("\nAttempting to remove node %c...", c );
    Node *itr;
    int move_right = compareNodes(c, root->char_data);

    switch (move_right) {
        case -1: {
            root->right = removeNodeRoot(root->right, c);
            break;
        }
        case 1: {
            root->left = removeNodeRoot(root->left, c);
            break;
        }
        case 0: {
            if (root->left == NULL) {
                itr = root->right;
                free(root);
                root = itr;
            }
            else if (root->right == NULL) {
                itr = root->left;
                free(root);
                root = itr;
            }
            else {
                itr = root->right;
                Node *parent = NULL;

                while (itr->left != NULL) {
                    parent = itr;
                    itr = itr->left;
                }

                root->char_data = itr->char_data;

                if (parent != NULL) {
                    parent->left = removeNodeRoot(parent->left, parent->left->char_data);
                }
                else {
                    root->right = removeNodeRoot(root->right, parent->right->char_data);
                }
            }
        }
    } // end switch

    return root;
}

int removeNode(unsigned char c) {
    printf("\nAttempting to remove node %c...", c);
    if (root == NULL) {
        printf(" No node to delete\n");
        return 0;
    }
    else {
        removeNodeRoot(root, c);
        printf(" Node Removed.");
    }
}

void numberLeafs() {
    unsigned int leafs = countLeafs(root);
    printf("\n\nNumber leaf Nodes in tree: %d.\n", leafs);
}

unsigned int countLeafs(Node *n) {
    if (n == NULL) {
        return 0;
    }
    if (n->left == NULL && n->right == NULL) {
        return 1;
    }
    else {
        return countLeafs(n->left) + countLeafs(n->right);
    }
}

unsigned int countDepth(Node *n) {
    if (n == NULL) {
        return 0;
    }
    else {
        int Ld = countDepth(n->left);
        int Rd = countDepth(n->right);

        if (Ld > Rd) {
            return (Ld + 1);
        }
        else {
            return (Rd + 1);
        }
    }
}

void printElementsAtDepth(int user) {
    printElementsAtDepthUTIL(root, user, 0);
}
void printElementsAtDepthUTIL(Node *n, int want, int at) {
    printf("\nShowing all elements at depth: %d. --> ", want);
    printNDepth(n, want, at);
}

void printTreeRoot(Node *n) {
    int leafs = countLeafs(n);
    int depth = countDepth(n);

    printf("\n\nNumber leafs: %d.", leafs);
    printf("\nTree depth (max): %d, +root = %d.\n", depth, depth + 1);

    int nodes_down = depth + 1;


    for (int i = 0; i < nodes_down; i++) {
        printf("Showing all elements at depth: %d. -->:", i);
        printNDepth(n, i, 0);
        printf("\n");
    }
}

void printNDepth(Node *n, int want, int at) {
    if (n == NULL) {
        return;
    }
    else {
        if (want == at) {
            printf(" %c ", n->char_data);
        }
        else {

            printNDepth(n->left, want, at + 1);
            printNDepth(n->right, want, at + 1);

        }
    }
}

void printTreePath(Node *n) {
    if (n == NULL) {
        return;
    }
    printf(" %c", n->char_data);
    if (n->left == NULL && n->right == NULL) {
        printf(" Is a leaf node");
    }
    if(n->left != NULL) {
        printf(" (On Left: %c)", n->left->char_data);
    }

    if(n->right != NULL) {
        printf("(On Right: %c)",n->right->char_data);
    }
    printf("\n");

    printTreePath(n->left);
    printTreePath(n->right);
}

void printTree() {
    if (root == NULL) {
        return;
    }
    else {
        printTreeRoot(root);
        printTreePath(root);
    }
}

void Done() {
    cleanTree(root);
}

void cleanTree(Node *root) {
    if (root != NULL) {
        cleanTree(root->left);
        cleanTree(root->right);
        free(root);
    }
}
