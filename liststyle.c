#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <liststyle.h>

Tree *create(){
    Tree *new_tree = calloc(1, sizeof(Tree));
    new_tree->size = 0;
	new_tree->root = NULL;
    return new_tree;
}
Node *build(int val){
    Node *node = calloc(1, sizeof(Node));
    node->val = val;
    return node;
}
/* Don't think i need this */
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

void addNode(Tree *tree, Node *parent, Node *new){
	if (parent->val == new->val){
		printf("Node Exists.\n");
	}
	/* Left Branch */
    else if (parent->val > new->val){
		/* If we find a child, recurse. */
		if (parent->left != NULL){
			addNode(parent->left, new);
		}
		else {
			parent->left = new;
			(tree->size)++;
		}
	} 
	/* Right Branch */
	else {
		/* If we find a child, recurse. */
		if (parent->right != NULL){
			addNode(parent->right, new);
		}
		else {
			parent->right = new;
			(tree->size)++;
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








