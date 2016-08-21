#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK editExpensesDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	struct Building *head = getHead();
	struct Building *building;
	struct Student *student;
	struct Expenses *expenses;
	struct Expenses *condition = getExpensesCondition();
	building = head;
	HWND idEditBox = GetDlgItem(hDlg, IDC_E_E_ID);
	HWND nameEditBox = GetDlgItem(hDlg, IDC_E_E_NAME);
	HWND dateEditBox = GetDlgItem(hDlg, IDC_E_E_DATE);
	HWND costEditBox = GetDlgItem(hDlg, IDC_E_E_COST);
	HWND usageEditBox = GetDlgItem(hDlg, IDC_E_E_USAGE);
	HWND officerEditBox = GetDlgItem(hDlg, IDC_E_E_OFFICER);
	switch (message)
	{
	case WM_INITDIALOG:{
		setDataToEditBox(idEditBox, condition->id);
		setDataToEditBox(nameEditBox, condition->name);
		setDataToEditBox(dateEditBox, condition->date);
		setDataToEditBox(costEditBox, floatToString(condition->cost));
		setDataToEditBox(usageEditBox, condition->usage);
		setDataToEditBox(officerEditBox, condition->officer);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_E_E_OK:{
			char *idInfo = (char*)malloc(sizeof(char) * 13);
			strcpy(idInfo, getDataFromEditBox(idEditBox, 12));
			char *nameInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(nameInfo, getDataFromEditBox(nameEditBox, 20));
			char *dateInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(dateInfo, getDataFromEditBox(dateEditBox, 20));
			char *costInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(costInfo, getDataFromEditBox(costEditBox, 20));
			char *usageInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(usageInfo, getDataFromEditBox(usageEditBox, 20));
			char *officerInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(officerInfo, getDataFromEditBox(officerEditBox, 20));
			if (strlen(idInfo) == 0 || strlen(nameInfo) == 0 || strlen(dateInfo) == 0 ||
				strlen(costInfo) == 0 || strlen(usageInfo) == 0 || strlen(officerInfo) == 0){
				MessageBox(hDlg, L"请填完所有的数据", L"提示", MB_OK);
			}
			else{
				while (building->nextBuilding != NULL){
					building = building->nextBuilding;
					student = building->firstStudent;
					while (student->nextStudent != NULL){
						student = student->nextStudent;
						expenses = student->firstExpenses;
						while (expenses->nextExpenses != NULL){
							expenses = expenses->nextExpenses;
							if (strcmp(expenses->id, condition->id) == 0 &&
								strcmp(expenses->name, condition->name) == 0 &&
								strcmp(expenses->date, condition->date) == 0 &&
								strcmp(floatToString(expenses->cost), floatToString(condition->cost)) == 0 &&
								strcmp(expenses->usage, condition->usage) == 0 &&
								strcmp(expenses->officer, condition->officer) == 0){
								strcpy(expenses->id, idInfo);
								strcpy(expenses->name, nameInfo);
								strcpy(expenses->date, dateInfo);
								expenses->cost = atof(costInfo);
								strcpy(expenses->usage, usageInfo);
								strcpy(expenses->officer, officerInfo);
								MessageBox(hDlg, L"修改成功", L"提示", MB_OK);
								EndDialog(hDlg, LOWORD(wParam));
							}
						}
					}
				}
			}
			break;
		}
		case IDC_E_E_CANCEL:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		}
		break;
	}
	}
	return (INT_PTR)FALSE;
}
