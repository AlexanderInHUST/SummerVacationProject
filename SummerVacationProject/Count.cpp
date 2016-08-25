#include "stdafx.h"
#include "SummerVacationProject.h"
#define NOW_YEAR 2016

float countArrearage(struct Student *student){
	struct Building *head = getHead();
	struct Building *building;
	struct Expenses *expenses;
	float arrearage = -1;
	float cost;
	float expensesAmount = 0;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		if (strcmp(building->num, student->building) == 0){
			cost = (NOW_YEAR - atoi(strtok(student->inTime, "/")) + 1) * building->cost;
			expenses = student->firstExpenses;
			while (expenses->nextExpenses != NULL){
				expenses = expenses->nextExpenses;
				expensesAmount = expensesAmount + expenses->cost;
			}
			arrearage = cost - expensesAmount;
		}
	}
	return ((int)arrearage == 0) ? -100 : arrearage;
}

int countDormitory(struct Building *building){
	int num = 0;
	struct Student *student = building->firstStudent;
	while (student->nextStudent != NULL){
		student = student->nextStudent;
		num++;
	}
	return num;
}

float countGender(char *size){
	float maleWeight;
	int amount = 0;
	int male = 0;
	bool found = false;
	struct Building *head = getHead();
	struct Building *building;
	struct Student *student;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			if (strcmp(student->category, size) == 0){
				found = true;
				amount++;
				if (student->gender == 'M'){
					male++;
				}
			}
		}
	}
	return (found) ? (float)male / (float)amount : -100;
}

float countIncome(struct Building *buildingInfo){
	struct Building *head = getHead();
	struct Building *building;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		if (strcmp(buildingInfo->num, building->num) == 0){
			return countDormitory(buildingInfo) * building->cost;
		}
	}
}

struct CountClass* countClass(){
	struct CountClass* classHead;
	struct CountClass* countClass;
	struct Building* head;
	struct Building* building;
	struct Student* student;
	head = getHead();
	classHead = (struct CountClass*)malloc(sizeof(struct CountClass));
	classHead->next = NULL;
	countClass = classHead;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			countClass = classHead;
			bool found = false;
			while (countClass->next != NULL){
				countClass = countClass->next;
				if (strcmp(countClass->clazz, student->clazz) == 0){
					found = true;
					countClass->num++;
					if (countArrearage(student) != -100){
						countClass->arrearage++;
					}
				}
			}
			if (!found){
				struct CountClass *temp = (struct CountClass*)malloc(sizeof(struct CountClass));
				strcpy(temp->clazz, student->clazz);
				temp->num = 1;
				temp->arrearage = (countArrearage(student) == -100) ? 0 : 1;
				countClass->next = temp;
				countClass = countClass->next;
				countClass->next = NULL;
			}
		}
	}
	return classHead;
}