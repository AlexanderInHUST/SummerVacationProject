#include "stdafx.h"
#include "SummerVacationProject.h"

// createExpensesData函数介绍
// 功能：分配出一个按照参数传入的值赋值好了的缴费数据的内存，然后返回内存的地址
// 返回值：创建好了的内存的地址

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