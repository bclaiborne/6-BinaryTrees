#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <liststyle.h>
#include <test.h>

int main(void){
	puts("Testing Node Creation");
    test_node();
	puts("Testing Tree Creation");
    test_tree();
	puts("Testing addNode().");
	test_addNode();
	puts("Testing all node functions.");
	test_return_funcs();
	puts("Tests Done.");
	return 0;
}
int test_node(){
    Node *root = build(5);
    assert(root != NULL);
    assert(root->val == 5);
    assert(root->left == NULL);
    assert(root->right == NULL);
    free(root);
    puts("Node Test Done.");
    return 0;
}
int test_tree(){
    Tree *tree = create();
    Node *root = build(5);
    tree->root = root;
    tree->size = 1;
    assert(tree != NULL);
    assert(tree->root != NULL);
    assert(tree->size == 1);
    
    free(root);
    free(tree);
    puts("Tree Test Done.");
    return 0;
}
int test_addNode(){
    Tree *tree = create();
    Node *root = build(5);
    tree->root = root;
    tree->size = 1;
	Node *node1 = build(4);
	Node *node2 = build(18);
	addNode(tree, root, node1);
	addNode(tree, root, node2);
	assert(root->left == node1);
	assert(root->right == node2);
	free(node1);
	free(node2);
	free(tree);
	return 0;
}
int test_return_funcs(){
	Tree *tree = create();
    tree->size = 1;
	int i;
	Node *cycle = build(48);
	tree->root = cycle;
	/* Test Tree Functions */
	puts("------ Return Functions Gibberish -------");
	assert(visit(tree->root) == 0);
	assert(preOrder(tree->root) == 0);
	assert(postOrder(tree->root) == 0);
	assert(inOrder(tree->root) == 0);
	
	puts("\n------ Function Gibberish Done. -------");
	return 0;
}