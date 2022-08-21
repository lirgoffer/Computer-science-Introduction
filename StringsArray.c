/* Assignment 4
autor: Lir Goffer, ID: 209103274*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50

char** init_arr(int*); //func that initials array of string and its size 
char** add(char**, int*, char*); //func that gets array of strings with its size and anouther string. the func create a new array and return it 
void twice(char**, int, int); //func that gets aaray of strings and its size with one index, and if the index is correct the func duplicate the index
int find(char**, int, char*); //func that gets array of strings and another string, it return the index of the string in the array if exist, if not its return -1
void print(char**, int); //func that gets array of string and print it
void freearry(char**, int); //func that free memory 
void enter(char**, int);// func that get the string from user 

int main() {

	int option, index, Psize, bool = 1;
	char** arr = NULL, ** temp = NULL, word[N];

	printf("Enter size of array:\n");
	scanf("%d", &Psize); //get size of array
	getchar();
	arr = init_arr(&Psize); //operate the func and allocate memory

	printf("Enter words:\n");
	enter(arr, Psize); //operate the func and get the words

	while (bool == 1) {

		printf("1-Add\n2-Twice\n3-Find\n4-Print\n5-End\n");
		scanf("%d", &option);
		getchar();

		switch (option) {
		case 1: //Add
			printf("Enter new word:\n");
			fgets(word, N, stdin); //get the word
			if (strlen(word) < N)
				word[(strlen(word) - 1)] = '\0'; //delete \n

			temp = add(arr, &Psize, word); //put in temp the new string array
			if (temp != NULL) {
				arr = temp; //update origin array
				printf("Done\n");
			}
			break;

		case 2: //Twice
			printf("Enter index:\n");
			scanf("%d", &index); //get the index
			if (index >= 0 && index < Psize) { //if index is correct
				twice(arr, Psize, index); //twice the word
				printf("Done\n");
			}
			else //if index isn't exist
				printf("Bad index\n");

			break;

		case 3: //Find
			printf("Enter word:\n");
			fgets(word, N, stdin); //get the word
			if (strlen(word) < N)
				word[(strlen(word) - 1)] = '\0'; //change \n

			if (find(arr, &Psize, word) == -1) { //if word dosn'n exist
				printf("Word not found\n");
			}
			else
				printf("Index:%d \n", find(arr, Psize, word)); //print the index of the word

			break;

		case 4: //Print
			print(arr, Psize);
			break;

		case 5: //End
			freearry(arr, Psize); //free memory
			printf("\nGoodbye\n");
			bool = 0;
			break;
		}
	}

	return 0;
}

char** init_arr(int* Psize) {
	int i,j;
	char** arrstr = NULL;

	arrstr = (char**)malloc(*Psize * sizeof(char*)); //allocate memory
	if (arrstr == NULL) {
		printf("Not enough memory");
		return NULL; //if there isn't enough memory
	}
	for (i = 0; i < *Psize; i++) {
		arrstr[i] = (char*)malloc(N * sizeof(char)); //allocate memory
		if (arrstr[i] == NULL) {
			printf("Not enough memory");

			for (j = 0; j < i; j++) { //free memory
				free(arrstr[j]);
				arrstr[j] = NULL;
			}
			free(arrstr); //free memory
			arrstr = NULL;

			return NULL; //if there isn't enough memory
		}
	}
	return arrstr; //return array with its memory
}

char** add(char** arr, int* psize, char* str) {
	int i;
	char** arr1;
	if (find(arr, *psize, str) == -1) { //if its a new word
		*psize += 1; //update size
		arr1 = init_arr(psize); //allocate new memory
		for (i = 0; i < (*psize - 1); i++)
			strcpy(arr1[i], arr[i]);  //copy origin array to the nwe one

		strcpy(arr1[*psize - 1], str); //add the new word

		freearry(arr, (*psize - 1)); //free old array
	}
	else
		return NULL;

	return arr1;
}

void twice(char** arr, int size, int index) {
	char temp[N];
	if (index < size && index >= 0) { //if index in the range
		strcpy(temp, arr[index]); //copy the word that in the index to temp
		strcat(arr[index], temp); //add the word to the array
	}
}

int find(char** arr, int size, char* str) {
	int i, j;
	for (i = 0; i < size; i++) { //run  the array
		for (j = 0; j < size; j++) {
			if (arr[i][j] == str[i]) //check if exist
				return i; //return the index
		}
	}
	return -1; //if word dosn't exist
}

void print(char** arr, int size) {
	int i;
	for (i = 0; i < size; i++) //print the array of strings
		printf("%s\n", arr[i]);
}

void freearry(char** arr, int size) {
	int i, j;
	for (i = 0; i < size; i++) {  //run the array
		for (j = 0; j < size; j++)
			arr[i][j] = NULL; //clean
	free(arr[i]); //free memory
	}
}

void enter(char** arr, int size) {
	int i;
	char word[N];
	for (i = 0; i < size; i++) {
		fgets(word, N, stdin); //get string
		if (strlen(word) < N)
			word[strlen(word) - 1] = '\0'; //clean \n
		strcpy(arr[i], word); //add string to array
	}
}