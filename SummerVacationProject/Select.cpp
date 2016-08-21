#include "stdafx.h"
#include "SummerVacationProject.h"

char *buildingData;
char *studentData;
struct Expenses *expensesData;

int setBuildingCondition(HWND hListView){
	int mark = ListView_GetSelectionMark(hListView);
	LPTSTR num = (LPTSTR)malloc(sizeof(LPTCH) * 6);
	ListView_GetItemText(hListView, mark, 0, num, 6);
	USES_CONVERSION;
	char *numString = (char*)malloc(sizeof(char) * 6);
	numString = T2A(num);
	buildingData = (char*)malloc(sizeof(char) * (strlen(numString) + 1));
	strcpy(buildingData, numString);
	return mark;
}

char* getBuildingCondition(){
	return buildingData;
}

int setStudentCondition(HWND hListView){
	int mark = ListView_GetSelectionMark(hListView);
	LPTSTR id = (LPTSTR)malloc(sizeof(LPTCH) * 13);
	ListView_GetItemText(hListView, mark, 0, id, 13);
	USES_CONVERSION;
	char *idString = (char*)malloc(sizeof(char) * 13);
	idString = T2A(id);
	studentData = (char*)malloc(sizeof(char) * (strlen(idString) + 1));
	strcpy(studentData, idString);
	return mark;
}

char* getStudentCondition(){
	return studentData;
}

int setExpensesCondition(HWND hListView){
	int mark = ListView_GetSelectionMark(hListView);
	LPTSTR id = (LPTSTR)malloc(sizeof(LPTCH) * 13);
	LPTSTR name = (LPTSTR)malloc(sizeof(LPTCH) * 21);
	LPTSTR date = (LPTSTR)malloc(sizeof(LPTCH) * 13);
	LPTSTR cost = (LPTSTR)malloc(sizeof(LPTCH) * 21);
	LPTSTR usage = (LPTSTR)malloc(sizeof(LPTCH) * 21);
	LPTSTR officer = (LPTSTR)malloc(sizeof(LPTCH) * 21);
	ListView_GetItemText(hListView, mark, 0, id, 13);
	ListView_GetItemText(hListView, mark, 1, name, 21);
	ListView_GetItemText(hListView, mark, 2, date, 13);
	ListView_GetItemText(hListView, mark, 3, cost, 21);
	ListView_GetItemText(hListView, mark, 4, usage, 21);
	ListView_GetItemText(hListView, mark, 5, officer, 21);
	USES_CONVERSION;
	char *idString = (char*)malloc(sizeof(char) * 13);
	char *nameString = (char*)malloc(sizeof(char) * 21);
	char *dateString = (char*)malloc(sizeof(char) * 13);
	char *costString = (char*)malloc(sizeof(char) * 21);
	char *usageString = (char*)malloc(sizeof(char) * 21);
	char *officerString = (char*)malloc(sizeof(char) * 21);
	expensesData = (struct Expenses*)malloc(sizeof(struct Expenses));
	idString = T2A(id);
	nameString = T2A(name);
	dateString = T2A(date);
	costString = T2A(cost);
	usageString = T2A(usage);
	officerString = T2A(officer);
	strcpy(expensesData->id, idString);
	strcpy(expensesData->name, nameString);
	strcpy(expensesData->date, dateString);
	expensesData->cost = atof(costString);
	strcpy(expensesData->usage, usageString);
	strcpy(expensesData->officer, officerString);
	return mark;
}

struct Expenses* getExpensesCondition(){
	return expensesData;
}