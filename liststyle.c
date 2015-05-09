#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <liststyle.h>

Tree *create(){
    Tree *new_tree = calloc(1, sizeof(Tree));
    new_tree->size = 0;
    return new_tree;
}
Node *build(int val){
    Node *node = calloc(1, sizeof(Node));
    node->val = val;
    return node;
}
int clearNode(Node *target){
    /* Base Case. Left and Right Empty. */
    if(target->left == NULL && target->right == NULL){
        /* The node has no children. Delete it.*/
        free(target);
        return 0;
    } /* Left Empty Case. */
    else if (target->left == NULL){
        /* Recurse down the right side. */
        clearNode(target->right);
    } /* Left Full Case. */
    else {
        /* Recurse down the left branch. */
        clearNode(target->left);
    }
    /* Notify Done. */
    puts("Tree Cleared.");
    return 0;
}
void addNode(Tree *tree, Node *parent){
    int val;
    (tree->size)++;    
    /* Base Case */
    if(parent->left != NULL & parent->right != NULL){
        printf("Node %d Complete.", parent->val);
        return;
    } 
    /* If left side is done, lets build the right. */
    else if (parent->left != NULL) {
        puts("Enter Right Value: ");
        scanf("%d", &val);
        if(val >= 0){
            /*recurse to populate new right node children. */
            addNode(tree, newChild(tree, parent, val, "R"));
        } else {
            puts("No Right Node Added.");
            return;
        }
    }
    /* If Left isn't done lets build one. */
    else {
        puts("Enter Left Value: ");
        scanf("%d", &val);
        if(val >= 0){
            /*recurse to populate new left node children. */
            addNode(tree, newChild(tree, parent, val, "L"));
        } else {
            puts("No Left Node Added.");
            return;
        }
    }
}
/* Creates a child node of value val on specified side. */
void *newChild(Tree *tree, Node *parent, int val, char *side){
    Node *new_node = build(val);
    new_node->tree = tree;
        if(side = "L"){
            parent->left->val = val;
        } else {
            parent->right->val = val;
        }
    return new_node;
}








