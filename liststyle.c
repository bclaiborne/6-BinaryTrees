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
    /* Avoid Duplicates */
	if (parent->val == new->val){
		printf("Node Exists.\n");
	}
	/* Left Branch */
    else if (parent->val > new->val){
		/* If we find a child, recurse. */
		if (parent->left != NULL){
			addNode(tree, parent->left, new);
		}
        /* Or save the value. */
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
        /* Or save the value. */
		else {
			parent->right = new;
			(tree->size)++;
		}
	}	
}
int preOrder(Node *current){
	/* Visits before recursion. */
	visit(current);
    if(current->left != NULL){preOrder(current->left);}
    if(current->right != NULL){preOrder(current->right);}
	return 0;
}
int inOrder(Node *current){
    if(current->left != NULL){inOrder(current->left);}
	/* Visit Between Recursions. */
	visit(current);
    if(current->right != NULL){inOrder(current->right);}
	return 0;
}
int postOrder(Node *current){
    if(current->left != NULL){postOrder(current->left);}
    if(current->right != NULL){postOrder(current->right);}
	/* Visit After Recursions */
	visit(current);
	return 0;
}
int visit(Node *node){
    /* "A node by any other name... is probably a Segmentation Fault." 
                -Wi11iam Sh8ksp3r3                                  */
	printf("%d, ", node->val);
	return 0;
}
int buildListTree(Tree *binary, int val){
    /* Create a node to add to the tree */
    Node *node = build(val);

    /* Special case: The tree root doesn't work in the recursive function. */
    if (binary->root == NULL){
        binary->root = node;
        binary->size++;
    } else {
        addNode(binary, binary->root, node);
    }
    return 0;
}
