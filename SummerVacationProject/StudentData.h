#include "stdafx.h"
#include "SummerVacationProject.h"

// 学生信息的结构体
// 两个指针是指向下一个结点的
// rec是指这个结点的唯一ID，nextRec是下一个学生的唯一ID，firstExpensesRec是指第一个缴费信息（头结点）的唯一ID

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

// 统计班级信息时的特殊结构体
// 拥有next指针
// 也有头结点

struct CountClass{
	char clazz[10];
	int num;
	int arrearage;
	struct CountClass *next;
};