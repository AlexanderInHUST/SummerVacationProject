#include "stdafx.h"
#include "SummerVacationProject.h"

struct Building* queryBuilding(char num[5], struct Building *head){
	struct Building *p = head;
	while (p->nextBuilding != NULL){
		p = p->nextBuilding;
		if (strcmp(p->num, num) == 0){
			return p;
		}
	}
	return NULL;
}

struct Student* queryStudentById(char id[12], struct Building *head){
	struct Building *building = head;
	struct Student *student;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			if (strcmp(student->id, id) == 0){
				return student;
			}
		}
	}
	return NULL;
}

struct Student* queryStudentByName(char name[12], struct Building *head){
	struct Building *building = head;
	struct Student *student;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			if (strcmp(student->name, name) == 0){
				return student;
			}
		}
	}
	return NULL;
}

struct Student* queryStudentListByName(char clazz[10], struct Building *head){
	struct Building *building = head;
	struct Student *student;
	struct Student *studentByClass;
	struct Student *headStudentByClass;
	bool exist = false;
	studentByClass = (struct Student*)malloc(sizeof(struct Student));
	headStudentByClass = studentByClass;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			if (strcmp(student->clazz, clazz) == 0){
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

