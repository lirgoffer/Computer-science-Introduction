/*assignment:4
Autor: Lir Goffer, ID:209103274*/

#define _CRT_SRCURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define size 50
void str_statistics(char[], int*, int*, int*);

int main() {
	char string[size];
	int capital = 0, small = 0, digits = 0; 
	printf("Enter a string:\n");
	gets(string); //get the string
	str_statistics(string, &capital, &small, &digits); //operate the func
	printf("%d small letters\n%d capital letters\n%d digits\n", small, capital, digits);
	
	return 0;
}

void str_statistics(char str[], int* capital, int* small, int* digits) {
	int i;

	for (i = 0; i < strlen(str); i++) { //run the string
		if (str[i] > 'A' && str[i] < 'Z') { //count the capital letters
			(*capital)++;
		}

		if (str[i] > 'a' && str[i] < 'z') { //count the small letters
			(*small)++;
		}

		if (str[i] >= '0' && str[i] <= '9') { //count the digits
			(*digits)++;
		}
	}
} 