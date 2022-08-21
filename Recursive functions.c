/*assignment 5 
autor: Lir Goffer, ID: 209103274*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int SumEvenDigits(long); //recursive func that gets long number and return the sum of even digits
long CreateNumber(long); //recursive func that gets long number and return new number from its odd digits
int CheckArithmeticSeries(long, int); //recursive func that gets long number and diff, and check if the digits of the long number is an arithmetc series
int OddNeg(int*, int, int*, int*); //recursive func that get array and return the number of the negative and the odd numbers
int Ascending(int[], int); //recursive func that gets array and its size and check is the array is in ascending order
void Reducing(char*); //recursive func that gets string and print the digits in it in a reverse order
int Symetric(char*, char*); //recursive func that gets pointers to the end and the begin of a string and check if palindrom

int main() {

	//________________q1_____________________//
	long num1 = 46729;
	printf("sum of even digits: %d\n", SumEvenDigits(num1)); //print func 1

	//_______________q2______________________//
	long num2 = 1234;
	printf("odd digits number: %d\n", CreateNumber(num2)); //print func 2


	//_______________q3____________________//
	long num3 = 3579;
	int diff = 2;
	printf("%d\n", CheckArithmeticSeries(num3, diff)); //print func 3


	//_______________q4_____________________//
	int arr[] = { 1,4,24,-88,75,70,-35,42 };
	int size = 8, neg=0, odd=0;
	
	OddNeg(arr,size, &neg, &odd); //operate func 
	printf("%d negative, %d odd\n", neg, odd); //print values

	//_______________q5______________________//
	int arr5[] = { 1,4,5,8,9 };
	int size5 = 5;
	printf("%d\n", Ascending(arr5, size5)); //print func 5

	//_______________q6______________________//
	char str[] = "Th8j23$%2kmn6}3h";
	Reducing(str); //operate func 
	printf("\n");

	//_______________q7______________________//
	char str7[] = "abba";
	char* begin = &str7[0], *end = &str7[3]; //pointers to the first and the last indexes
	printf("%d\n", Symetric(begin, end)); //print func 7

	return 0;
}

int SumEvenDigits(long num) {
	if (num == 0) //base case
		return 0;

	if (num % 2 == 0) 
		return SumEvenDigits(num / 10) + num % 10; //add the even digits

	return SumEvenDigits(num / 10); //in case the digit is odd

}

long CreateNumber(long number) {
	if (number == 0) //base case
		return 0;

	if (number % 2 == 1) 
		return number%10 +10* CreateNumber(number / 10); //build the odd number

	return CreateNumber(number / 10); //in case the digits is even

}

int CheckArithmeticSeries(long Number, int Diff) {
	if (Number < 10) //if the number has one digit
		return 1;
	if (Number % 10 - Diff == Number / 10 % 10) //if the follows digits is series
		return CheckArithmeticSeries(Number / 10, Diff); 
	else //if not series
		return 0;

}

int OddNeg(int* arr, int size, int* neg, int* odd) {
	
	if (size == 0) //base
		return 0;

	if (arr[size - 1] % 2 == 1) //check if odd
		(*odd)++;
	if (arr[size - 1] < 0) //check if neg
		(*neg)++;

	return OddNeg(arr, size-1, neg, odd); 
}


int Ascending(int arr[], int size) {
	if (size == 0 || size == 1) //if array has 0 or 1 numbers
		return 1;
	if (arr[size - 1] >= arr[size - 2]) //if the numbers are in ascending order
		return Ascending(arr, size - 1); 

	else //if not in ascending order
		return 0;
	}

void Reducing(char* str) {

	if (strlen(str) > 0) { //while the size is not 0
		if (str[strlen(str) - 1] >= '0' && str[strlen(str) - 1] <= '9') //check if the char is a number from the end of the string to the begining
			printf("%c", str[strlen(str) - 1]); //print the number

		str[strlen(str) - 1] = '\0'; //delete the last char
		Reducing(str); //call the func with the updated string
	}
}

int Symetric(char* begin, char* end) {

		if (*begin != *end) //if different
			return 0;
		else 	//if same		
			return 1;

		if (*begin =='\0') //if string over
			return 1;

		Symetric(begin + 1, end - 1); //operate with new indexs
}
