#include "stdafx.h"
#include "SummerVacationProject.h"

struct Expenses* loadExpensesList(struct Student* student){
	FILE *file;
	struct Expenses *preHead = createExpensesData("head", "head", "head", -1, "head", "head", NULL, 0);
	struct Expenses *head = (struct Expenses*)malloc(sizeof(struct Expenses));
	struct Expenses *p;
	if ((file = fopen("data_of_expenses.dat", "r")) == NULL){
		return NULL;
	}
	p = preHead;
	preHead->nextExpenses = head;
	preHead->nextRec = student->firstExpensesRec;
	while (1){
		struct Expenses *expenses = (struct Expenses*)malloc(sizeof(struct Expenses));
		if (fscanf(file, "%d %s %s %s %f %s %s %d\n",
			&expenses->rec, expenses->id, expenses->name, expenses->date, &expenses->cost, expenses->usage, expenses->officer, &expenses->nextRec) == EOF){
			break;
		}
		if (expenses->rec == p->nextRec){
			p->nextExpenses = expenses;
			p = p->nextExpenses;
		}
	}
	p->nextExpenses = NULL;
	fclose(file);
	return preHead->nextExpenses;
}

struct Student* loadStudentList(struct Building* building){
	FILE *file;
	struct Student *preHead = createStudentData("head", "head", 'H', "head", "head", -1, "head", "head", "head", "head", "head", NULL, NULL, 0);
	struct Student *head = (struct Student*)malloc(sizeof(struct Student));
	struct Student *p;
	if ((file = fopen("data_of_student.dat", "r")) == NULL)
		return NULL;
	p = preHead;
	preHead->nextStudent = head;
	preHead->nextRec = building->firstStudentRec;
	while (1){
		struct Student *student = (struct Student*)malloc(sizeof(struct Student));
		if (fscanf(file, "%d %s %s %c %s %s %d %s %s %s %s %s %d %d\n",
			&student->rec, student->id, student->name, &student->gender, student->birth, student->category, &student->size, student->inTime, student->clazz, student->building, student->room, student->tel, &student->nextRec, &student->firstExpensesRec) == EOF){
			break;
		}
		if (student->rec == p->nextRec){
			p->nextStudent = student;
			p = p->nextStudent; 
		}
	}
	p->nextStudent = NULL;
	fclose(file);
	return preHead->nextStudent;
}

struct Building* loadBuildingList(){
	FILE *file;
	struct Building *preHead = createBuildingData("head", "head", "head", -1, -1, -1, NULL, NULL, 0);
	struct Building *head = (struct Building*)malloc(sizeof(struct Building));
	struct Building *p;
	if ((file = fopen("data_of_building.dat", "r")) == NULL)
		return NULL;
	p = preHead;
	preHead->nextBuilding = head;
	preHead->nextRec = 0;
	while (1){
		struct Building *building = (struct Building*)malloc(sizeof(struct Building));
		if (fscanf(file, "%d %s %s %s %d %d %f %d %d\n",
			&building->rec, building->num, building->administrator, building->tel, &building->rooms, &building->beds, &building->cost, &building->nextRec, &building->firstStudentRec) == EOF){
			break;
		}
		if (building->rec == p->nextRec){
			p->nextBuilding = building;
			p = p->nextBuilding;
		}
	}
	p->nextBuilding = NULL;
	fclose(file);
	return preHead->nextBuilding;
}

struct Building* loadAllData(){
	struct Building *head;
	head = loadBuildingList();
	struct Building *building = head;
	if (head == NULL){
		head = createBuildingData("head", "head", "head", -1, -1, -1, NULL, NULL, 0);
		return head;
	}
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		building->firstStudent = loadStudentList(building);
		struct Student *head;
		struct Student *student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			student->firstExpenses = loadExpensesList(student);
		}
	}
	return head;
}