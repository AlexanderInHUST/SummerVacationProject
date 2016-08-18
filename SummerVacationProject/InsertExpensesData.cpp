#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK insertExpensesDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	struct Building *head = getHead();
	struct Building *building;
	struct Student *student;
	struct Expenses *expenses;
	building = head;
	switch (message)
	{
	case WM_INITDIALOG:{
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_I_E_OK:{
			HWND idEditBox = GetDlgItem(hDlg, IDC_I_E_ID);
			HWND nameEditBox = GetDlgItem(hDlg, IDC_I_E_NAME);
			HWND dateEditBox = GetDlgItem(hDlg, IDC_I_E_DATE);
			HWND costEditBox = GetDlgItem(hDlg, IDC_I_E_COST);
			HWND usageEditBox = GetDlgItem(hDlg, IDC_I_E_USAGE);
			HWND officerEditBox = GetDlgItem(hDlg, IDC_I_E_OFFICER);
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
				bool found = false;
				while (building->nextBuilding != NULL){
					building = building->nextBuilding;
					student = building->firstStudent;
					while (student->nextStudent != NULL){
						student = student->nextStudent;
						if (strcmp(student->id, idInfo) == 0){
							found = true;
							expenses = student->firstExpenses;
							while (expenses->nextExpenses != NULL){
								expenses = expenses->nextExpenses;
							}
							struct Expenses *newExpenses = createExpensesData(idInfo, nameInfo, dateInfo, atof(costInfo), usageInfo, officerInfo, NULL, expenses->nextRec);
							expenses->nextExpenses = newExpenses;
							MessageBox(hDlg, L"添加成功", L"提示", MB_OK);
							EndDialog(hDlg, LOWORD(wParam));
						}
					}
				}
				if (!found){
					MessageBox(hDlg, L"未找到相应的学生信息", L"提示", MB_OK);
				}
			}
			break;
		}
		case IDC_I_E_CANCEL:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		}
		break;
	}
	}
	return (INT_PTR)FALSE;
}