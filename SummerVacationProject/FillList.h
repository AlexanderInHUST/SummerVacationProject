#include "stdafx.h"
#include "SummerVacationProject.h"

void fillBuildingList(HWND hListView, LVITEM vitem, struct Building *building, int count);
void fillStudentList(HWND hListView, LVITEM vitem, struct Student *student, int count);
void fillExpensesList(HWND hListView, LVITEM vitem, struct Expenses *expenses, int count);
int fillCountArrearage(HWND hListView, LVITEM vitem);
int fillCountDormitory(HWND hListView, LVITEM vitem);
int fillCountGender(HWND hListView, LVITEM vitem);
int fillCountIncome(HWND hListView, LVITEM vitem);
int fillCountClass(HWND hListView, LVITEM vitem);