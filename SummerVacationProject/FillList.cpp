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
	int num = 0;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		num = countDormitory(building);
		vitem.pszText = stringToLPWSTR(building->num);
		vitem.iSubItem = 0;
		ListView_InsertItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(intToString(building->beds - num));
		vitem.iSubItem = 1;
		ListView_SetItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(intToString(num));
		vitem.iSubItem = 2;
		ListView_SetItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(intToString(building->beds - num));
		vitem.iSubItem = 3;
		ListView_SetItem(hListView, &vitem);
		vitem.pszText = stringToLPWSTR(floatToString((float)num / (float)building->beds * 100));
		vitem.iSubItem = 4;
		ListView_SetItem(hListView, &vitem);
	}
	return 1;
}

int fillCountGender(HWND hListView, LVITEM vitem){
	float male;
	float female;
	char categories[3][10] = { "本科", "硕士", "博士" };
	for (int i = 0; i < 3; i++){
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