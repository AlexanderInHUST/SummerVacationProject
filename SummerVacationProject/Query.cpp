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
			student = student->nextStudent;
			if (strcmp(student->id, id) == 0){
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

