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
	if (firstExpenses == NULL){
		newStudent->firstExpensesRec = getID();
		newStudent->firstExpenses = createExpensesData("head", "head", "head", -1, "head", "head", NULL, newStudent->firstExpensesRec);
		newStudent->firstExpenses->nextExpenses = NULL;
	}
	else{
		newStudent->firstExpenses = firstExpenses;
		newStudent->firstExpensesRec = firstExpenses->rec;
	}
	if (nextStudent == NULL){
		newStudent->nextRec = getID();
	}
	else{
		newStudent->nextRec = nextStudent->rec;
	}
	newStudent->nextStudent = nextStudent;
	newStudent->rec = rec;
	return newStudent;
}