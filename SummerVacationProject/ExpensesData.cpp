#include "stdafx.h"
#include "SummerVacationProject.h"

struct Expenses* createExpensesData(
	char id[12],
	char name[20],
	char date[12],
	float cost,
	char usage[20],
	char officer[20],
	struct Expenses *nextExpenses,
	int rec){

	struct Expenses *newExpenses;

	newExpenses = (struct Expenses*)malloc(sizeof(struct Expenses));

	strcpy(newExpenses->id, id);
	strcpy(newExpenses->name, name);
	strcpy(newExpenses->date, date);
	newExpenses->cost = cost;
	strcpy(newExpenses->usage, usage);
	strcpy(newExpenses->officer, officer);
	if (nextExpenses == NULL){
		newExpenses->nextRec = getID();
	}
	else{
		newExpenses->nextRec = newExpenses->rec;
	}
	newExpenses->nextExpenses = nextExpenses;
	newExpenses->rec = rec;
	return newExpenses;
}