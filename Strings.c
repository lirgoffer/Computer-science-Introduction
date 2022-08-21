/*assighnment: 3 part 3
autor: Lir Goffer, iD:209103274*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define size 80
void rotate_left(char[size]); //get string, delete the first word and add it to the end
void rotate_right(char[size]); //get string, delete the last word and add it to the begining
int intersection(char[], char[]); //get two strings and return the number of same index

int main() {
	int i;
	char str1[size];
	char str2[size];
	printf("please enter the first sring:\n");
	gets(str1); //get the string
	printf("please enter the second string:\n");
	gets(str2); //get the string


	for (i = 0; i < 2; i++) {
		rotate_right(str1); //run the func two times
	}
	printf("first string after 2 rotation right: %s", str1);

	for (i = 0; i < 3; i++) {
		rotate_left(str2); //run the func three times
	}
	printf("second string after 3 rotation left: %s", str2);
	
	printf("intersection of the last two strings: %d", intersection(str1, str2));

	return 0;
}

void rotate_left(char string[size]) {
	
	int i, j, k, wordlen = 0;
	char temp[size] = { 0 };
	char firstword[size] = { 0 };
	int stringlen = strlen(string);
	 
	for (i = 0; i < size; i++) { //check the lengh of the firs word
		wordlen++;
		if (string[i] == ' ') {
			break;
		}
	}

	for (i = 0; i < wordlen; i++) { //copy the first word
		firstword[i] = string[i];
	}
	
	for (j = 0; j < size; j++) { //copy the string without the first word
		for (k = wordlen; string[k] != '\n'; k++) {
			temp[j] = string[k];
		}
	}


	strcat(temp, firstword); //add the first word to the end
	strcpy(string, temp); //copy the new string to the original
}

void rotate_right(char string[size]) {
	int i, wordlen = 0;
	char temp[size] = { 0 };
	char lastword[size] = { 0 };

	for (i = strlen(string); i > 0; i--) {  //check the lengh of the last word
		while (string[i] != '\0') {
			wordlen++;
		}
	}

	for (i = strlen(string)-wordlen; i=strlen(string); i++) { //copy the last word
		lastword[i] = string[i];
	}

	for (i = 0; i = (strlen(string) - wordlen); i++) { //copy the strig without the last word
		temp[i] = string[i];
	}

	strcat(lastword, temp); //add the string without the last word to the string of th last word
	strcpy(string, lastword); //copy the new string to the original

}




int intersection(char str1[], char str2[]) {
	int i, j, count = 0;

	for (i = 0, j = 0; i < strlen(str1), j < strlen(str2); i++, j++) { //run the strings
			if ((str1[i] == str2[j]) || ((str1[i] == ' ') && (str2[j] == ' '))) 
				count++;
		}

	
	return count;
}

