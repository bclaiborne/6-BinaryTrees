#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arraystyle.h>

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
		if (branchSafe(lefty, array)){
			addEntry(array, lefty, value);
		}
		else {
			array[lefty] = value;
		}
	} 
	/* Right Branch */
	else {
		/* If we find a child, recurse. */
		if (branchSafe(righty, array)){
			addEntry(array, righty, value);
		}
		else {
			array[righty] = value;
		}
	}	
}
int arrPreOrder(int *array, int index){
    /* Get the child nodes for branching */
	int lefty = childL(index);
	int righty = childR(index);
	
	/* Visits before recursion. */
	arrVisit(array, index);
    if(branchSafe(lefty, array)){arrPreOrder(array, lefty);}
    if(branchSafe(righty, array)){arrPreOrder(array, righty);}
	return 0;
}
int arrInOrder(int *array, int index){
    /* Get the child nodes for branching */
	int lefty = childL(index);
	int righty = childR(index);
	
    if(branchSafe(lefty, array)){arrInOrder(array, lefty);}
	/* Visit Between Recursions. */
	arrVisit(array, index);
	if(branchSafe(righty, array)){arrInOrder(array, righty);}
	return 0;
}
int arrPostOrder(int *array, int index){
    /* Get the child nodes for branching */
	int lefty = childL(index);
	int righty = childR(index);
	
    if(branchSafe(lefty, array)){arrPostOrder(array, lefty);}
	if(branchSafe(righty, array)){arrPostOrder(array, righty);}
	/* Visit After Recursions */
	arrVisit(array, index);
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
    return 2*index + 1;
}
int branchSafe(int index, int *array){
	/* Just checks if the index is a valid array index and has a value so we can flow down the tree. */
	if(index <= 255 && array[index] != 0){
		return 1;
	} else {
		return 0;
	}
}
int buildArrayTree(int *array, int val){
    /* Start the array */
    if (array[0] == 0){
        array[0] = val;
    }
    /* Build from there */
    else {
        addEntry(array, 0, val);
    }

    return 0;
}