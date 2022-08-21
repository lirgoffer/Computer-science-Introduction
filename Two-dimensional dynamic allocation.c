/*assignment: 4
autor: Lir Goffer, ID:209103274*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long long** shrink(long long**, int, int*);
long long addnum(long long, long long);
long long** buildmatrix(int); //func that allocate memory for the matrix
void addelemet(long long**, int); //func that add the numbers to the new matrix
void freearr(long long**, int); //func that free memory of the matrix
void printarr(long long**, int); //func that print the matrix

int main() {

	long long** Mat;
	int size, pSize;
	printf("Enter size of matrix:\n");
	scanf("%d", &size); //get the size of the matrix

	Mat = buildmatrix(size); //operate func and aloocate memory
	addelemet(Mat, size); //operate func and fill 
	Mat = shrink(Mat, size, &pSize); //operate func
	printarr(Mat, pSize); //operate func and print the matrix
	freearr(Mat, pSize); //operate the func and free all memory

	return 0;
}

long long** shrink(long long** a, int size, int* pSize) {

	long long** arr = NULL, tempnum;

	if (size % 2 != 0) { //check if size is odd
		freearr(a, size);
		return NULL;
	}

	*pSize = (size / 2); //update pSize
	arr = buildmatrix(*pSize); //allocate memory

	for (int i = 0; i < *pSize; i++) { //run the original matrix
		tempnum = 0;
		for (int j = 0; j < *pSize; j++) {
			tempnum = addnum(a[i * 2][j * 2], a[i * 2][j * 2 + 1]); //add first two numbers
			tempnum = addnum(tempnum, a[i * 2 + 1][j * 2]); //add third number
			tempnum = addnum(tempnum, a[i * 2 + 1][j * 2 + 1]); //add forth number
			arr[i][j] = tempnum; //get the index to the new matrix
		}
	}
	freearr(a, size); //free memory
	return arr;
}

long long addnum(long long num1, long long num2) {

	long long temp = num1;
	while (num2 != 0) { //add the numbers by digits
		temp *= 10;
		temp += num2 % 10;
		num2 /= 10;
	}
	return temp; //return the new number
}

long long** buildmatrix(int size) {

	long long** matrix;

	matrix = (long long**)malloc(size * sizeof(long long*)); //allocate memory
	if (matrix == NULL) {
		printf("Not enough memory");
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		matrix[i] = (long long*)malloc(size * sizeof(long long)); //allocate memory
		if (matrix[i] == NULL) {
			printf("Not enough memory");
			for (int j = 0; j < i; j++) { //free memory
				free(matrix[j]);
			}
			free(matrix); //free memory
			exit(1);
		}
	}
	return matrix; //return matrix with allocate memory 
}

void addelemet(long long** arr, int size) { 

	printf("Enter the matrix:\n");
	for (int i = 0; i < size; i++) { //get the matrix from user
		for (int j = 0; j < size; j++) {
			scanf("%lld", &arr[i][j]);
		}
	}
}

void freearr(long long** arr, int size) { 

	for (int i = 0; i < size; i++) { //run the matrix
		for (int j = 0; j < size; j++) {
			arr[i][j] = NULL;
		}
		free(arr[i]); //free memory
	}
	free(arr); //free memory
}

void printarr(long long** arr, int size) {

	printf("new matrix:\n");
	for (int i = 0; i < size; i++) { //run the matrix
		for (int j = 0; j < size; j++) {
			printf("%lld   ", arr[i][j]); //print all index
		}
		printf("\n");
	}
}