#include "stdafx.h"
#include "SummerVacationProject.h"

// ѧ����Ϣ�Ľṹ��
// ����ָ����ָ����һ������
// rec��ָ�������ΨһID��nextRec����һ��ѧ����ΨһID��firstExpensesRec��ָ��һ���ɷ���Ϣ��ͷ��㣩��ΨһID

struct Student{
	char id[12];
	char name[12];
	char gender;
	char birth[12];
	char category[15];
	short size;
	char inTime[8];
	char clazz[10];
	char building[5];
	char room[5];
	char tel[20];
	struct Expenses *firstExpenses;
	struct Student *nextStudent;

	int rec;
	int nextRec;
	int firstExpensesRec;
};

struct Student* createStudentData(
	char id[12],
	char name[20],
	char gender,
	char birth[12],
	char category[15],
	short size,
	char inTime[8],
	char clazz[10],
	char building[5],
	char room[5],
	char tel[20],
	struct Expenses *firstExpenses,
	struct Student *nextStudent,
	int rec);

// ͳ�ư༶��Ϣʱ������ṹ��
// ӵ��nextָ��
// Ҳ��ͷ���

struct CountClass{
	char clazz[10];
	int num;
	int arrearage;
	struct CountClass *next;
};