#include "stdafx.h"
#include "SummerVacationProject.h"

// 缴费信息的结构体
// 这个指针是指向下一个结点的
// rec是指这个结点的唯一ID，nextRec是下一个缴费的唯一ID

struct Expenses{
	char id[12];
	char name[20];
	char date[12];
	float cost;
	char usage[20];
	char officer[20];
	struct Expenses *nextExpenses;

	int rec;
	int nextRec;
};

struct Expenses* createExpensesData(
	char id[12],
	char name[20],
	char date[12],
	float cost,
	char usage[20],
	char officer[20],
	struct Expenses *nextExpenses,
	int rec);