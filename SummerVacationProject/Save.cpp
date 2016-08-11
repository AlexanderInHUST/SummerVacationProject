#include "stdafx.h"
#include "SummerVacationProject.h"

int saveBuildingData(struct Building* head){
	FILE *file;
	struct Building *p;
	p = head;
	if ((file = fopen("data_of_building.dat", "w")) == NULL){
		return -1;
	}
	fprintf(file, "%d|%s|%s|%s|%d|%d|%f|%d|%d\n",
		p->rec, p->num, p->administrator, p->tel, p->rooms, p->beds, p->cost, p->nextRec, p->firstStudentRec);
	while (p->nextBuilding != NULL){
		p = p->nextBuilding;
		fprintf(file, "%d|%s|%s|%s|%d|%d|%f|%d|%d\n",
			p->rec, p->num, p->administrator, p->tel, p->rooms, p->beds, p->cost, p->nextRec, p->firstStudentRec);
	}
	fclose(file);
	return 1;
}

int saveStudentData(struct Building* head){
	FILE *file;
	struct Building *building;
	struct Student *student;
	building = head;
	if ((file = fopen("data_of_student.dat", "w")) == NULL){
		return -1;
	}
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		fprintf(file, "%d|%s|%c|%s|%s|%d|%s|%s|%s|%s|%s|%d|%d\n",
			student->rec, student->name, student->gender, student->birth, student->category, student->size, student->inTime, student->clazz, student->building, student->room, student->tel, student->nextRec, student->firstExpensesRec);
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			fprintf(file, "%d|%s|%c|%s|%s|%d|%s|%s|%s|%s|%s|%d|%d\n",
				student->rec, student->name, student->gender, student->birth, student->category, student->size, student->inTime, student->clazz, student->building, student->room, student->tel, student->nextRec, student->firstExpensesRec);
		}
	}
	fclose(file);
	return 1;
}

int saveExpensesData(struct Building* head){
	FILE *file;
	struct Building *building;
	struct Student *student;
	struct Expenses *expenses;
	building = head;
	if ((file = fopen("data_of_expenses.dat", "w")) == NULL){
		return -1;
	}
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			expenses = student->firstExpenses;
			fprintf(file, "%d|%s|%s|%s|%f|%s|%s|%d\n",
				expenses->rec, expenses->id, expenses->name, expenses->date, expenses->cost, expenses->usage, expenses->officer, expenses->nextRec);
			while (expenses->nextExpenses != NULL){
				expenses = expenses->nextExpenses;
				fprintf(file, "%d|%s|%s|%s|%f|%s|%s|%d\n",
					expenses->rec, expenses->id, expenses->name, expenses->date, expenses->cost, expenses->usage, expenses->officer, expenses->nextRec);
			}
		}
	}
	fclose(file);
	return 1;
}