#include "bst.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

    insertNode('E');
    insertNode('D');
    insertNode('F');
    insertNode('C');
    insertNode('G');
    insertNode('B');
    insertNode('H');
    insertNode('A');
    insertNode('I');

    printTree();

    searchNode('F');
    searchNode('D');


    removeNode('H');
    removeNode('F');

    printTree();


    printElementsAtDepth(3);
    printElementsAtDepth(4);

    numberLeafs();


    Done();
    return 0;
}
