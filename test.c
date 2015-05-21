#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <liststyle.h>
#include <test.h>

int main(){
    int array[255] = {0};
    int ar_size = 0;
	int i = 0;
	
	array[0] = 7;

	puts("Testing Node Creation");
    test_node();
	puts("Testing Tree Creation");
    test_tree();
	puts("Testing addNode()");
	test_addNode();
    puts("Testing children index functions.");
    test_childValues();
    puts("Testing addEntry()");
	test_addEntry(array);
    test_Order(array);
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
int test_childValues(){
    int left = childL(5);
    int right = childR(5);

    assert(left == 11);
    assert(right == 12);
    return 0;
}
int test_addEntry(int *array){
	assert(array[1] == 0);
	assert(array[2] == 0);
	/* Greater than should go in index 2. */
	addEntry(array, 0, 10);
	assert(array[2] == 10);
	/* Less than should go in index 1. */
	addEntry(array, 0, 5);
	assert(array[1] == 5);
	/* Lower layers recursion tests. */
	addEntry(array, 0, 9);
	addEntry(array, 0, 11);
	assert(array[5] == 9);
	assert(array[6] == 11);
	return 0;
}
int test_Order(int *array){
    int i=0;
    for(i=0; i<10; i++){
        addEntry(array, 0, i);
    }
    puts("Array PreOrder");
    arrPreOrder(array,0);
    puts("\nArray InOrder");
    arrInOrder(array,0);
    puts("\nArray PostOrder");
    arrPostOrder(array,0);
    puts("");
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