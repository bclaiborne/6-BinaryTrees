#include <stdio.h>
#include <string.h>

#include "liststyle.h"
#include "arraystyle.h"

int main(){
    /* For 8 tiers, its 2^8 array locations = 256. */
    int array[255] = {0};
    int ar_size = 0;
	Tree *binary = create();
	
	int val = 0;
	while (val >= 0){
		puts("Enter Value: ");
		scanf("%d", &val);
		
		/* Negative values terminate the tree. */
		if(val < 0){ break;	}
        
        buildArrayTree(array, val);
        ar_size++;
        buildListTree(binary, val);
        
        /* Output */
		printf("Tree Size:   %d\n", binary->size);
		printf("Array Size:  %d\n", ar_size);
		printf("\nPreOrder Sequence:  ");
		preOrder(binary->root);
		printf("\nArrayPre Sequence:  ");
		arrPreOrder(array, 0);
		printf("\nInOrder Sequence:   ");
		inOrder(binary->root);
		printf("\nArrayIn Sequence:   ");
		arrInOrder(array, 0);
		printf("\nPostOrder Sequence: ");
		postOrder(binary->root);
		printf("\nArrayPost Sequence: ");
		arrPostOrder(array, 0);
		puts("");
	}
	puts("Value was negative. Ending Input\n");
	
return 0;
}