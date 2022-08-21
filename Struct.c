/*Assignment: 5
Autor: Lir Goffer, ID:209103274*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {  //struct of day work
	int DayNumber; //1-31
	int WorkHours; // 1-12
} WorkDay;

typedef struct { //struct of worker
	long ID; 
	int HourlySal; 
	int workdays;
	WorkDay* wd; 
	double salary;
} Worker;
	

void InputWorkDay(WorkDay*); //func that get info of work hours for worker 
void PrintWorkDay(WorkDay); //func that print info of work hours for worker
void InputWorker(Worker*); //func that get info of worker
void PrintWorker(Worker); //func that print info of worker
Worker* InitFactory(int*); //func that create and initial array of workers in factory
void PrintFactory(Worker*, int); //func that print all data of factoty
void CalculateSalary(Worker* ,int); //func that calaulate total salary

int main() {

	Worker* pFactory = NULL; 
	int size;
	pFactory = InitFactory(&size); //get the array of workers
	CalculateSalary(pFactory, size); //operate func and calculate total salary
	PrintFactory(pFactory, size); //operate func and print all data

	free(pFactory); //free memory
	pFactory = NULL;
	
	return 0;
}

void InputWorkDay(WorkDay* pWD) {

		printf("Enter day number: ");
		scanf("%d", &pWD->DayNumber); //get the day number
		printf("Enter work hours: ");
		scanf("%d", &pWD->WorkHours); //get the work hours
		printf("\n");
	
}

void PrintWorkDay(WorkDay wd) {
	printf("work day data: Day %d , %d hours\n", wd.DayNumber, wd.WorkHours); //print data
}

void InputWorker(Worker* pW) {
	int i;
	printf("Enter worker ID: \n");
	scanf("%ld", &pW->ID); //get ID
	printf("Enter hourly salary: \n");
	scanf("%d", &pW->HourlySal);//get hourly salary
	printf("Enter number of work days this mounth: \n");
	scanf("%d", &pW->workdays);//get number of work days

	pW->wd = (WorkDay*)malloc(sizeof(WorkDay) * pW->workdays); //allocate memory
	if (pW->wd == NULL) {
		printf("Not enough memory");
		exit(1);
	}

	for (i = 0; i < pW->workdays; i++) { //operate the func and get data for the days of work
		InputWorkDay(&(pW->wd[i]));
	}
}

void PrintWorker(Worker w) {
	int i;
	printf("worker data:\n ID: %ld\n Hourly salary: %d\n Number of work days: %d\n Total salary: %lf\n", w.ID, w.HourlySal, w.workdays, w.salary); //print data
	for (i = 0; i < w.workdays; i++) 
		PrintWorkDay(w.wd[i]); //opearte the func and print data
}

Worker* InitFactory(int* pSize) {
	Worker* workers = NULL;
	int i;
	printf("Enter number of workers:\n");
	scanf("%d", pSize); //get the number of workers
	workers = (Worker*)malloc(sizeof(Worker) * *pSize); //allocate memory
	if (workers == NULL) {
		printf("Not enough memory");
		exit(1);
	}
	for (i = 0; i < *pSize; i++) { //get data from user
		InputWorker(&workers[i]);
	}
	return workers; //return the array of workers
}

void PrintFactory(Worker* pWorker, int size) {
	int i;
	for (i = 0; i < size; i++) { //print data for every worker
		PrintWorker(pWorker[i]); 
		printf("\n");
	}
}

void CalculateSalary(Worker* pWorker, int size) {
	double temp = 0;
	int i;
	for (i = 0; i < size; i++)
		temp += (pWorker->HourlySal* pWorker->wd[i].WorkHours); //calaulate for each day of work

	pWorker->salary = temp; //update value of salary
}