#include <stdio.h>
#include <string.h>

#include "liststyle.h"
#include "arraystyle.h"

extern int array[255];
extern int arr_size;

int main(){
	Tree *binary = create();
	
	int val = 0;
	while (val >= 0){
		puts("Enter Value: ");
		scanf("%d", &val);
		
		/* Negative values terminate the tree. */
		if(val < 0){ break;	}
		
		/* Create a node to add to the tree */
		Node *node = build(val);
		/* Start the array */
		if (array[0] == 0){
			array[0] = val;
		}
		else {
			addEntry(array, 0, val);
		}
		
		/* Special case: The tree root doesn't work in the recursive function. */
		if (binary->root == NULL){
			binary->root = node;
			binary->size++;
		} else {
			addNode(binary, binary->root, node);
		}
		printf("Tree Size: %d", binary->size);
		printf("\nPreOrder Sequence: ");
		preOrder(binary->root);
		printf("\nInOrder Sequence: ");
		inOrder(binary->root);
		printf("\nPostOrder Sequence: ");
		postOrder(binary->root);
		puts("");
	}
	puts("Value was negative. Ending Input\n");
	
return 0;
}