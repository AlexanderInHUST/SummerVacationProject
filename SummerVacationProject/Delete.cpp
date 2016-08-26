#include "stdafx.h"
#include "SummerVacationProject.h"

// deleteBuildingData函数介绍
// 功能：删除在hListView中被选中的宿舍楼数据结点，并且重新链接整个链表
// 返回值：无

void deleteBuildingData(struct Building *head, HWND hListView, HWND hWND){
	struct Building *building = head;
	int mark = ListView_GetSelectionMark(hListView);
	LPTSTR num = (LPTSTR)malloc(sizeof(LPTCH) * 6);
	ListView_GetItemText(hListView, mark, 0, num, 6);
	USES_CONVERSION;
	char *numString = (char*)malloc(sizeof(char) * 6);
	numString = T2A(num);
	
	//从选中的数据中获得每个宿舍楼的唯一标识num，然后在搜索整个链表删除
	
	bool found = false;
	if (mark == -1){
		MessageBox(hWND, L"请先选中一条信息", L"异常", MB_OK);
		return;
	}
	while (building->nextBuilding != NULL){
		if (strcmp(building->nextBuilding->num, numString) == 0){
			found = true;
			struct Building *temp = building->nextBuilding->nextBuilding;
			building->nextRec = building->nextBuilding->nextRec;
			free(building->nextBuilding);
			building->nextBuilding = temp;
			MessageBox(hWND, L"删除成功", L"提示", MB_OK);
			return;
		}
		building = building->nextBuilding;
	}
	if (!found){
		MessageBox(hWND, L"异常错误，未找到相应楼信息", L"异常", MB_OK);
	}
}

// deleteStudentData函数介绍
// 功能：删除在hListView中被选中的学生数据结点，并且重新链接整个链表
// 返回值：无

void deleteStudentData(struct Building *head, HWND hListView, HWND hWND){
	struct Building *building = head;
	struct Student *student;
	int mark = ListView_GetSelectionMark(hListView);
	LPTSTR id = (LPTSTR)malloc(sizeof(LPTCH) * 13);
	ListView_GetItemText(hListView, mark, 0, id, 13);
	USES_CONVERSION;
	char *idString = (char*)malloc(sizeof(char) * 13);
	idString = T2A(id);

	//从选中的数据中获得每个学生的唯一标识id，然后在搜索整个链表删除
	
	bool found = false;
	if (mark == -1){
		MessageBox(hWND, L"请先选中一条信息", L"异常", MB_OK);
		return;
	}
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			if (strcmp(student->nextStudent->id, idString) == 0){
				found = true;
				struct Student *temp = student->nextStudent->nextStudent;
				student->nextRec = student->nextStudent->nextRec;
				free(student->nextStudent);
				student->nextStudent = temp;
				MessageBox(hWND, L"删除成功", L"提示", MB_OK);
				return;
			}
			student = student->nextStudent;
		}
	}
	if (!found){
		MessageBox(hWND, L"异常错误，未找到相应楼信息", L"异常", MB_OK);
	}
}

// deleteExpensesData函数介绍
// 功能：删除在hListView中被选中的缴费数据结点，并且重新链接整个链表（由于缴费数据没有唯一标识，只能全部一一对应起来）
// 返回值：无

void deleteExpensesData(struct Building *head, HWND hListView, HWND hWND){
	struct Building *building = head;
	struct Student *student;
	struct Expenses *expenses;
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
	idString = T2A(id);
	nameString = T2A(name);
	dateString = T2A(date);
	costString = T2A(cost);
	usageString = T2A(usage);
	officerString = T2A(officer);
	
	//从选中的数据中获得每个缴费数据的所有标识，然后在搜索整个链表删除
	
	bool found = false;
	if (mark == -1){
		MessageBox(hWND, L"请先选中一条信息", L"异常", MB_OK);
		return;
	}
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			expenses = student->firstExpenses;
			while (expenses->nextExpenses != NULL){
				if (strcmp(expenses->nextExpenses->id, idString) == 0 &&
					strcmp(expenses->nextExpenses->name, nameString) == 0 &&
					strcmp(expenses->nextExpenses->date, dateString) == 0 &&
					strcmp(floatToString(expenses->nextExpenses->cost), costString) == 0 &&
					strcmp(expenses->nextExpenses->usage, usageString) == 0 &&
					strcmp(expenses->nextExpenses->officer, officerString) == 0){
					found = true;
					struct Expenses *temp = expenses->nextExpenses->nextExpenses;
					expenses->nextRec = expenses->nextExpenses->nextRec;
					free(expenses->nextExpenses);
					expenses->nextExpenses = temp;
					MessageBox(hWND, L"删除成功", L"提示", MB_OK);
					return;
				}
				expenses = expenses->nextExpenses;
			}
		}
	}
	if (!found){
		MessageBox(hWND, L"异常错误，未找到相应楼信息", L"异常", MB_OK);
	}
}