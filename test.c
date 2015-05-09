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

