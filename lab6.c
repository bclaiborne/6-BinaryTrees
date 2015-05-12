#include <stdio.h>
#include <string.h>

#include "liststyle.h"

int main(){
	Tree *binary = create();
	int val = 0;
	while (val >= 0){
		puts("Enter Value: \n");
		scanf("%d", &val);
		
		/* Negative values terminate the tree. */
		if(val < 0){ break;	}
		
		/* Create a node to add to the tree */
		Node *node = build(val);
		
		/* Special case: The tree root doesn't work in the recursive function. */
		if (binary->root == NULL){
			binary->root = node;
		} else {
			addNode(binary, binary->root, node);
		}
	}
	puts("Value was negative. Ending Input\n");
	
return 0;
}