#include "stdafx.h"
#include "SummerVacationProject.h"

// �ɷ���Ϣ�Ľṹ��
// ���ָ����ָ����һ������
// rec��ָ�������ΨһID��nextRec����һ���ɷѵ�ΨһID

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