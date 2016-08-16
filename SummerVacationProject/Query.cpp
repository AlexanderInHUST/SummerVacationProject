#include "stdafx.h"
#include "SummerVacationProject.h"

struct Building* queryBuilding(char num[5], struct Building *head){
	struct Building *p = head;
	char innerNum[5];
	strcpy(innerNum, num);
	while (p->nextBuilding != NULL){
		p = p->nextBuilding;
		if (strcmp(p->num, innerNum) == 0){
			return p;
		}
	}
	return NULL;
}

struct Student* queryStudentById(char id[12], struct Building *head){
	struct Building *building = head;
	struct Student *student;
	char innerId[12];
	strcpy(innerId, id);
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			if (strcmp(student->id, innerId) == 0){
				return student;
			}
		}
	}
	return NULL;
}

struct Student* queryStudentListByName(char name[12], struct Building *head){
	struct Building *building = head;
	struct Student *student;
	struct Student *studentByName;
	struct Student *headStudentByName;
	char innerName[12];
	bool exist = false;
	strcpy(innerName, name);
	studentByName = (struct Student*)malloc(sizeof(struct Student));
	headStudentByName = studentByName;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			if (strcmp(student->name, innerName) == 0){
				exist = true;
				struct Student *temp =
					createStudentData(student->id, student->name, student->gender, student->birth, student->category, student->size, student->inTime, student->clazz, student->building, student->room, student->tel, student->firstExpenses, NULL, -1);
				studentByName->nextStudent = temp;
				studentByName = studentByName->nextStudent;
			}
		}
	}
	return (exist == false) ? NULL : headStudentByName;
}

struct Student* queryStudentListByClass(char clazz[10], struct Building *head){
	struct Building *building = head;
	struct Student *student;
	struct Student *studentByClass;
	struct Student *headStudentByClass;
	char innerClazz[10];
	bool exist = false;
	strcpy(innerClazz, clazz);
	studentByClass = (struct Student*)malloc(sizeof(struct Student));
	headStudentByClass = studentByClass;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			if (strcmp(student->clazz, innerClazz) == 0){
				exist = true;
				struct Student *temp =
					createStudentData(student->id, student->name, student->gender, student->birth, student->category, student->size, student->inTime, student->clazz, student->building, student->room, student->tel, student->firstExpenses, NULL, -1);
				studentByClass->nextStudent = temp;
				studentByClass = studentByClass->nextStudent;
			}
		}
	}
	return (exist == false) ? NULL : headStudentByClass;
}

struct Expenses* queryHeadExpensesByStudent(char id[12], struct Building *head){
	struct Student* student = queryStudentById(id, head);
	if (student == NULL || student->firstExpenses == NULL){
		return NULL;
	}
	else{
		return student->firstExpenses;
	}
}

