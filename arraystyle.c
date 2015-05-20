#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arraystyle.h>
	/* For 8 tiers, its 2^8 array locations = 256. */
    int array[255] = {0};
    int ar_size = 0;

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
		if (array[lefty] != 0){
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
		if (array[righty] != 0){
			addEntry(array, righty, value);
		}
		else {
			array[righty] = value;
            ar_size++;
		}
	}	
}
int arrPreOrder(int *array, int index){
	int lefty = childL(index);
	int righty = childR(index);
	
	/* Visits before recursion. */
	visit(array[index]);
    if(branchSafe(lefty, array)){preOrder(array, lefty);}
    if(branchSafe(righty, array)){preOrder(array, righty);}
	return 0;
}
int arrInOrder(int *array, int index){
	int lefty = childL(index);
	int righty = childR(index);
	
    if(branchSafe(lefty, array)){inOrder(array, lefty);}
	/* Visit Between Recursions. */
	visit(array[index]);
	if(branchSafe(righty, array)){inOrder(array, righty);}
	return 0;
}
int arrPostOrder(int *array, int index){
	int lefty = childL(index);
	int righty = childR(index);
	
    if(branchSafe(lefty, array)){postOrder(array, lefty);}
	if(branchSafe(righty, array)){postOrder(array, righty);}
	/* Visit After Recursions */
	visit(array[index]);
	return 0;
}
int arrVisit(int *array, int index){
	printf("%d, ", array[index]);
	return 0;
}
/* children location functions */
int childR(int index){
    return 2*index + 2;
}
int childL(int index){
    return 2*index +1;
}
int branchSafe(int index, int *array){
	/* Just checks if the index is a valid array index and has a value so we can flow down the tree. */
	if(index <= 255 && array[index] != 0){
		return 1;
	} else {
		return 0;
	}
}
