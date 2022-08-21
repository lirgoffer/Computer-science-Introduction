/*assignment:4
Autor: Lir Goffer, ID:209103274*/

#define _CRT_SRCURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int* divide(int[], int, int[], int); //func that create array of the numbers from a array that divide by b array

int main() {
	int size_a, size_b, * ptra = NULL, * ptrb = NULL, * ptrc = NULL;
	int i;
	
	printf("Enter size of a:\n");
	scanf_s("%d", &size_a); //get the size of a

	ptra = (int*)malloc(size_a * sizeof(int)); //alocate memory
	if (ptra == NULL) {
		printf("not enough memory\n");
		exit(1);
	}

	printf("Enter %d elements of a:\n", size_a);
	for (i = 0; i < size_a; i++) {
		scanf_s("%d", &ptra[i]); //get the numbers of a
	}

	
	printf("Enter size of b:\n");
	scanf_s("%d", &size_b); //get the size of b

	ptrb = (int*)malloc(size_b * sizeof(int)); //alocate memory
	if (ptrb == NULL) {
		printf("not enough memory\n");
		free(ptra);
		exit(1);
	}

	printf("Enter %d elements of b:\n", size_b); 
	for (i = 0; i < size_b; i++) {
		scanf_s("%d", &ptrb[i]); //get the numbers of b
	}

	for (i = 0; i < size_b; i++) { //change the 0 in array b to 1
		if (ptrb[i] == 0)
			ptrb[i]= 1;
	}

	ptrc = (int*)malloc(size_b * sizeof(int));
	if (ptrc == NULL) {
		printf("not enough memory\n");
		free(ptra);
		free(ptrb);
		exit(1);
	}

	ptrc=divide(ptra, size_a, ptrb, size_b); //operate the func
	printf("C array:\n");
	for (i = 0; i < size_b; i++) { //print array c
		printf("%d ", ptrc[i]);
}

	free(ptra); //free memory
	free(ptrb);
	free(ptrc);
	return 0;
}

int* divide(int* a, int size_a, int* b, int size_b) {
	int *ptrc=NULL;
	int i, j;
	
	ptrc =calloc(size_b, sizeof(int)); //allocate memory
	if (ptrc == NULL) {
		printf("not enough memory\n");
		exit(1);
	}

	for (i = 0; i < size_b; i++) { //run b array
		ptrc[i]=0;
		for (j = 0; j < size_a; j++) { //run a array
			if (a[j] % b[i] == 0) { //check if divide
				ptrc[i]++;
			}
		}
	}

	return ptrc; //return c array
}