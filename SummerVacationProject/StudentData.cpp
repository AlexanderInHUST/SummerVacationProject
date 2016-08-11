#include "stdafx.h"
#include "SummerVacationProject.h"

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
	int rec){

	struct Student* newStudent;

	newStudent = (struct Student*)malloc(sizeof(struct Student));

	strcpy(newStudent->id, id);
	strcpy(newStudent->name, name);
	newStudent->gender = gender;
	strcpy(newStudent->birth, birth);
	strcpy(newStudent->category, category);
	newStudent->size = size;
	strcpy(newStudent->inTime, inTime);
	strcpy(newStudent->clazz, clazz);
	strcpy(newStudent->building, building);
	strcpy(newStudent->room, room);
	strcpy(newStudent->tel, tel);
	newStudent->firstExpenses = firstExpenses;
	newStudent->nextStudent = nextStudent;
	newStudent->rec = rec;
	newStudent->nextRec = getID();
	newStudent->firstExpensesRec = getID();
	return newStudent;
}