#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <stdbool.h> /*new header*/
#include "avl.h"

int FindMinPath(struct AVLTree *tree, TYPE *path);
void printBreadthFirstTree(struct AVLTree *tree);
void printLevel(struct AVLnode* root, int level); /*new function*/
void preorder(struct AVLnode* node, int* minCost, int *mincostpath, int* minCostPathLength, 
                int* candidatePath, int* candidatePathLength, int sumdiff, int parentVal); /*new function*/
/* -----------------------
The main function
  param: argv = pointer to the name (and path) of a file that the program reads for
adding elements to the AVL tree
*/
int main(int argc, char** argv) {
    FILE *file;
    int len, i;
    TYPE num; /* value to add to the tree from a file */
    struct timeval stop, start; /* variables for measuring execution time */
    int pathArray[100];  /* static array with values of nodes along the min-cost 
    path of the AVL tree. The means that the depth of the AVL tree cannot be greater 
    than 100 which is  sufficient for our purposes*/
    struct AVLTree *tree;
    tree = newAVLTree(); /*initialize and return an empty tree */
    file = fopen(argv[1], "r");  /* filename is passed in argv[1] */
    assert(file != 0);

    /* Read input file and add numbers to the AVL tree */
    while((fscanf(file, "%i", &num)) != EOF) {
        addAVLTree(tree, num);
    }

    /* Close the file  */
    fclose(file);

    printf("\nThe AVL tree has %d nodes.\n",tree->cnt);
    printf("\nPrinting the AVL tree breadth-first : \n");
    printBreadthFirstTree(tree);
    gettimeofday(&start, NULL);

    /* Find the minimum-cost path in the AVL tree*/
    len = FindMinPath(tree, pathArray);
    gettimeofday(&stop, NULL);

    /* Print out all numbers on the minimum-cost path */
    printf("\n\nThe minimum-cost path has %d nodes printed top-down from the root to the leaf: \n", len);
    for(i = 0; i < len; i++)
    printf("%d ", pathArray[i]);
    printf("\n");
    printf("\nYour execution time to find the mincost path is %f microseconds\n",
    (double) (stop.tv_usec - start.tv_usec));
            /* Free memory allocated to the tree */
    deleteAVLTree(tree); 
    return 0;
}
  
/* --------------------
Finds the minimum-cost path in an AVL tree
   Input arguments: 
        tree = pointer to the tree,
        path = pointer to array that stores values of nodes along the min-cost 
path, 
   Output: return the min-cost path length 
   pre: assume that
       path is already allocated sufficient memory space 
       tree exists and is not NULL
*/
int FindMinPath(struct AVLTree *tree, TYPE *path) { /*find minimum cost path here*/
    /* FIX ME */

    /*Do a predorder function. There are 3 steps:
    1) Make a candidate path (you don't know if its the shortest)
    2) Calculate the cost for the candidate path
    3) Check if there is a left or right node. If there is, call preorder function on left and right.
    4) Compare cost of candidate path with previously known minimum cost path
    5) If the candidate path is cheaper, replace min cost path with candidate path*/

    int minCostPathLength = 0;
    struct AVLnode* current = tree->root;
    int minCost = 9999999;
    int candidatePathLength = 0;
    int candidatePath[1000];

    if (tree->cnt > 1) {
        preorder(current, &minCost, path, &minCostPathLength, candidatePath, &candidatePathLength, 0, current->val);
    }

    /*int pathIndex, val;
    if ((current->left == NULL) && (current->right == NULL)) {
        return val;
    }
    while (current->left != NULL) {
        val = val + abs(current->left->val - current->val);
        current = current->left;
    }
    return val;*/
    return minCostPathLength;
}

int absValue (int a, int b) { /*New function*/
    int absoluteVal = a - b;
    if (a - b < 0) {
        absoluteVal = absoluteVal * -1;
    }
    return absoluteVal;
}

void preorder(struct AVLnode* node, int* minCost, int *mincostpath, int* minCostPathLength, 
                int* candidatePath, int* candidatePathLength, int sumdiff, int parentVal) {
    int i;
    candidatePath[*candidatePathLength] = node->val;
    (*candidatePathLength)++;
    sumdiff = sumdiff + absValue(parentVal, node->val);
    /*if (node->left || node->right) {
        preorder(node->left, minCost, mincostpath, minCostPathLength, candidatePath, candidatePathLength, sumdiff, node->val);
        preorder(node->right, minCost, mincostpath, minCostPathLength, candidatePath, candidatePathLength, sumdiff, node->val);
    }*/
    if (node->left && sumdiff < *minCost) {
        preorder(node->left, minCost, mincostpath, minCostPathLength, candidatePath, candidatePathLength, sumdiff, node->val);
        (*candidatePathLength)--;
    }
    if (node->right && sumdiff < *minCost) {
        preorder(node->right, minCost, mincostpath, minCostPathLength, candidatePath, candidatePathLength, sumdiff, node->val);
        (*candidatePathLength)--;
    }
    if (*minCost > sumdiff && node->left == NULL && node->right == NULL) {
        /*replace mincostpath with candidatepath*/
        for (i = 0; i < *candidatePathLength; i++) {
            mincostpath[i] = candidatePath[i];
        }
        *minCostPathLength = *candidatePathLength;
        *minCost = sumdiff;
    }
}

/* -----------------------
Printing the contents of an AVL tree in breadth-first fashion
  param: pointer to a tree
  pre: assume that tree was initialized well before calling this function
*/
void printBreadthFirstTree(struct AVLTree *tree) { /*print the values of all the nodes from left to right, top to down*/
    /* FIX ME */
    int height = h(tree->root);
    int i;
    for (i = 0; i <= height; i++) {
        printLevel(tree->root, i);
    }
}

void printLevel(struct AVLnode* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 0) {
        printf("%d ", root->val);
    }
    else if (level > 0) {
        _balance(root);
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}