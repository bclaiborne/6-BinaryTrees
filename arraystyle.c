#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arraystyle.h>

/* For 8 tiers, its 2^8 array locations = 256. */
int main(){
    int array[255] = {0};
    int ar_size = 0;
    
}
void addEntry(int *array, int index, int value){
    
    /* Find the next two children locations */
    int lefty = childL(index);
    int righty = childR(index);
    
	if (array[index] == value){
		printf("Value Exists.\n");
	}
	/* Left Branch */
    else if (array[index] > value){
		/* If we find a child, recurse. */
		if (array[lefty] != NULL){
			addEntry(array, lefty, value);
		}
		else {
			array[lefty] = value;
            ar_size++;
		}
	} 
	/* Right Branch */
	else {
		/* If we find a child, recurse. */
		if (array[righty] != NULL){
			addEntry(array, righty, value);
		}
		else {
			array[righty] = value;
            ar_size++;
		}
	}	
}
int preOrder(int *array, int index){
	/* Visits before recursion. */
	visit(array[index]);
	leftSide(array[index]);
	rightSide(array[index]);
	return 0;
}
int inOrder(int *array, int index){
	leftSide(array[index]);
	/* Visit Between Recursions. */
	visit(array[index]);
	rightSide(array[index]);
	return 0;
}
int postOrder(int *array, int index){
	leftSide(array[index]);
	rightSide(array[index]);
	/* Visit After Recursions */
	visit(array[index]);
	return 0;
}
int visit(int *array, int index){
	printf("%d, ", array[index]);
	return 0;
}
int leftSide(int *array, int index){
	/* Recurse down the left side of a branch */
	if(node->left != NULL){
		leftSide(array, childL(index));
	}
	return 0;
}
int rightSide(int *array, int index){
	/* Recurse down the right side of a branch */
	if(node->right != NULL){
		rightSide(array, childR(index));
	}
	return 0;
}
/* children location functions */
int childR(int index){
    return 2*index + 2;
}
int childL(int index){
    return 2*index +1;
}