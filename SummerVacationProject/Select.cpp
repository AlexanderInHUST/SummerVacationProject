#include "stdafx.h"
#include "SummerVacationProject.h"

// 此文件是为了解决对话框之间无法传输数据的问题，只能临时使用一个结构体来存储选中的数据
// 以下函数只用于编辑功能之中

char *buildingData;
char *studentData;
struct Expenses *expensesData;

// setBuildingCondition函数介绍
// 功能：将选中的宿舍楼数据的唯一标识num放入到buildingData中
// 返回值：是否选中（没选中mark将返回-1）

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

// getBuildingCondition函数介绍
// 功能：返回buildingData
// 返回值：buildingData

char* getBuildingCondition(){
	return buildingData;
}

// setBuildingCondition函数介绍
// 功能：将选中的学生数据的唯一标识id放入到studentData中
// 返回值：是否选中（没选中mark将返回-1）

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

// getStudentCondition函数介绍
// 功能：返回studentData
// 返回值：studentData

char* getStudentCondition(){
	return studentData;
}

// setExpensesCondition函数介绍
// 功能：将选中的缴费数据的所有标识符放入到expensesData中
// 返回值：是否选中（没选中mark将返回-1）

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

// getExpensesCondition函数介绍
// 功能：返回expensesData
// 返回值：expensesData

struct Expenses* getExpensesCondition(){
	return expensesData;
}