/*assighnment:3 part 2
autor: Lir Goffer, ID:209103274*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int sumline(int[][5]); //func that gets matrix and return the sum of the biggest value in each row
int sumcol(int[][5]); //func that gets matrix and return the sum of the biggest value in each col 
int neigh(int[][5]); //funt that cheak the neighbors and return their amount

int main() {
	int i, j;
	int mat[5][5];

	printf("please enter 5 arrays of 5 integers:\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf("%d", &mat[i][j]); //get the matrix
		}
	}

	printf("Sum of maximums of lines: %d\n", sumline(mat)); //call the func
	printf("sum of maximums of cols: %d\n", sumcol(mat));
	
	printf("num of neighbors is: %d\n", neigh(mat));
	return 0;
}

int sumline(int arr[][5]) {  
	int i, j;
	int temp = 0;
	int sum = 0;
	for (i = 0; i < 5; i++) {  //run the matrix
		temp = 0;
		for (j = 0; j < 5; j++) {
			if (arr[i][j] >= temp) //check which value is the biggest
				temp = arr[i][j];
		}
		sum += temp; 
	}
	return sum;
}

int sumcol(int arr[][5]) {
	int i, j;
	int temp = 0;
	int sum = 0;
	for (i = 0; i < 5; i++) { //run the matrix
		temp = 0;
		for (j = 0; j < 5; j++) { //run by col
			if (arr[j][i] >= temp) //check which value is the biggest
				temp = arr[j][i];
		}
		sum += temp;
	}
	return sum;
}

int neigh(int arr[][5]) {

	int i, j;
	int count = 0;

	for (i = 0; i < 5; i++) { //run the matrix
		for (j = 0; j < 4; j++) {
			if (arr[i][j] == arr[i][j + 1]) //check by rows
				count++;
		}
	}
	
	for (i = 0; i < 4; i++) { //run the matrix
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == arr[i + 1][j]) //check by col
				count++;
		}
	}

	for (i = 0; i < 4; i++) { //run the matrix
		for (j = 0; j < 4; j++) {
			if (arr[i][j] == arr[i + 1][j + 1]) //check \ diagonals
				count++;
		}
	}

	for (i = 0; i < 4; i++) { //run the matrix
		for (j = 4; j > 0; j--) {
			if (arr[i][j] == arr[i + 1][j - 1]) //check / diagonals
				count++;

		}
	}
	return count;	
}
