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

void addNode(Tree *tree, Node *parent, Node *new){
	if (parent->val == new->val){
		printf("Node Exists.\n");
	}
	/* Left Branch */
    else if (parent->val > new->val){
		/* If we find a child, recurse. */
		if (parent->left != NULL){
			addNode(tree, parent->left, new);
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
			addNode(tree, parent->right, new);
		}
		else {
			parent->right = new;
			(tree->size)++;
		}
	}	
}
int preOrder(Node *current){
	/* Visits before recursion. */
	visit(current);
	leftSide(current);
	rightSide(current);
	return 0;
}
int inOrder(Node *current){
	leftSide(current);
	/* Visit Between Recursions. */
	visit(current);
	rightSide(current);
	return 0;
}
int postOrder(Node *current){
	leftSide(current);
	rightSide(current);
	/* Visit After Recursions */
	visit(current);
	return 0;
}
int visit(Node *node){
	printf("%d, ", node->val);
	return 0;
}
int leftSide(Node *node){
	/* Recurse down the left side of a branch */
	if(node->left != NULL){
		leftSide(node->left);
	}
	return 0;
}
int rightSide(Node *node){
	/* Recurse down the right side of a branch */
	if(node->right != NULL){
		rightSide(node->right);
	}
	return 0;
}