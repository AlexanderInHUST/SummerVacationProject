#include "stdafx.h"
#include "SummerVacationProject.h"

void fillBuildingList(HWND hListView, LVITEM vitem, struct Building *building, int count){
	vitem.pszText = stringToLPWSTR(building->num);
	vitem.iSubItem = 0;
	ListView_InsertItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(building->administrator);
	vitem.iSubItem = 1;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(building->tel);
	vitem.iSubItem = 2;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(intToString(building->rooms));
	vitem.iSubItem = 3;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(intToString(building->beds));
	vitem.iSubItem = 4;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(floatToString(building->cost));
	vitem.iSubItem = 5;
	ListView_SetItem(hListView, &vitem);
}

void fillStudentList(HWND hListView, LVITEM vitem, struct Student *student, int count){
	vitem.pszText = stringToLPWSTR(student->id);
	vitem.iSubItem = 0;
	ListView_InsertItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(student->name);
	vitem.iSubItem = 1;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = charToLPWSTR(student->gender);
	vitem.iSubItem = 2;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(student->birth);
	vitem.iSubItem = 3;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(student->category);
	vitem.iSubItem = 4;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(intToString(student->size));
	vitem.iSubItem = 5;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(student->inTime);
	vitem.iSubItem = 6;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(student->clazz);
	vitem.iSubItem = 7;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(student->building);
	vitem.iSubItem = 8;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(student->room);
	vitem.iSubItem = 9;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(student->tel);
	vitem.iSubItem = 10;
	ListView_SetItem(hListView, &vitem);
}

void fillExpensesList(HWND hListView, LVITEM vitem, struct Expenses *expenses, int count){
	vitem.pszText = stringToLPWSTR(expenses->id);
	vitem.iSubItem = 0;
	ListView_InsertItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(expenses->name);
	vitem.iSubItem = 1;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(expenses->date);
	vitem.iSubItem = 2;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(floatToString(expenses->cost));
	vitem.iSubItem = 3;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(expenses->usage);
	vitem.iSubItem = 4;
	ListView_SetItem(hListView, &vitem);
	vitem.pszText = stringToLPWSTR(expenses->officer);
	vitem.iSubItem = 5;
	ListView_SetItem(hListView, &vitem);
}

int fillCountArrearage(HWND hListView, LVITEM vitem){
	struct Building *head = getHead();
	struct Building *building;
	struct Student *student;
	int count = 0;
	float arrearage;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			arrearage = countArrearage(student);
			if ((int)arrearage != -100){
				count++;
				vitem.pszText = stringToLPWSTR(student->id);
				vitem.iSubItem = 0;
				ListView_InsertItem(hListView, &vitem);
				vitem.pszText = stringToLPWSTR(student->name);
				vitem.iSubItem = 1;
				ListView_SetItem(hListView, &vitem);
				vitem.pszText = stringToLPWSTR(student->building);
				vitem.iSubItem = 2;
				ListView_SetItem(hListView, &vitem);
				vitem.pszText = stringToLPWSTR(floatToString(arrearage));
				vitem.iSubItem = 3;
				ListView_SetItem(hListView, &vitem);
			}
		}
	}
	return count;
}

int fillCountDormitory(HWND hListView, LVITEM vitem){
	struct Building *head = getHead();
	struct Building *building;
	struct countDocumentory *headOfArray;
	struct countDocumentory *array;
	int num = 0;
	int amount = 0;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		amount++;
	}
	headOfArray = (struct countDocumentory*)malloc(sizeof(struct countDocumentory) * amount);
	array = headOfArray;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		num = countDormitory(building);
		array->ratio = (float)num / (float)building->beds * 100;
		array->occupied = num;
		array->amount = building->beds;
		strcpy(array->num, building->num);
		array++;
	}
	qsort(headOfArray, amount, sizeof(struct countDocumentory), cmp);
	array = headOfArray;
	for (int i = 0; i < amount; i++){
		vitem.pszText = stringToLPWSTR(array->num);
		vitem.iSubItem = 0;
		ListView_InsertItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(intToString(array->amount - array->occupied));
		vitem.iSubItem = 1;
		ListView_SetItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(intToString(array->occupied));
		vitem.iSubItem = 2;
		ListView_SetItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(intToString(array->amount - array->occupied));
		vitem.iSubItem = 3;
		ListView_SetItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(floatToString(array->ratio));
		vitem.iSubItem = 4;
		ListView_SetItem(hListView, &vitem);
		array++;
	}
	return 1;
}

int fillCountGender(HWND hListView, LVITEM vitem){
	float male;
	float female;
	char categories[4][10] = { "专科", "本科", "硕士", "博士" };
	for (int i = 0; i < 4; i++){
		vitem.iItem = i;
		male = countGender(categories[i]);
		if ((int)male == -100){
			male = 0;
			female = 0;
		}
		else{
			female = 1 - male;
		}
		vitem.pszText = stringToLPWSTR(categories[i]);
		vitem.iSubItem = 0;
		ListView_InsertItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(floatToString(male * 100));
		vitem.iSubItem = 1;
		ListView_SetItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(floatToString(female * 100));
		vitem.iSubItem = 2;
		ListView_SetItem(hListView, &vitem);
	}
	return 1;
}

int fillCountIncome(HWND hListView, LVITEM vitem){
	struct Building *head = getHead();
	struct Building *building;
	int count = 0;
	building = head;
	float cost;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		cost = countIncome(building);
		vitem.iItem = count++;
		vitem.pszText = stringToLPWSTR(building->num);
		vitem.iSubItem = 0;
		ListView_InsertItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(floatToString(cost));
		vitem.iSubItem = 1;
		ListView_SetItem(hListView, &vitem);
	}
	return 1;
}

int fillCountClass(HWND hListView, LVITEM vitem){
	struct CountClass *head = countClass();
	struct CountClass *countClass;
	countClass = head;
	int count = 0;
	while (countClass->next != NULL){
		countClass = countClass->next;
		vitem.iItem = count++;
		vitem.pszText = stringToLPWSTR(countClass->clazz);
		vitem.iSubItem = 0;
		ListView_InsertItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(intToString(countClass->num));
		vitem.iSubItem = 1;
		ListView_SetItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(intToString(countClass->arrearage));
		vitem.iSubItem = 2;
		ListView_SetItem(hListView, &vitem);
	}
	return 0;
}