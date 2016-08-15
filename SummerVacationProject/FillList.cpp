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