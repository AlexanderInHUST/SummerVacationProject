#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK editStudentDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	struct Building *head = getHead();
	struct Building *building;
	struct Student *student;
	char *condition = getStudentCondition();
	building = head;
	HWND idEditBox = GetDlgItem(hDlg, IDC_E_S_ID);
	HWND nameEditBox = GetDlgItem(hDlg, IDC_E_S_NAME);
	HWND genderEditBox = GetDlgItem(hDlg, IDC_E_S_GENDER);
	HWND birthEditBox = GetDlgItem(hDlg, IDC_E_S_BIRTH);
	HWND categoryEditBox = GetDlgItem(hDlg, IDC_E_S_CATEGORY);
	HWND sizeEditBox = GetDlgItem(hDlg, IDC_E_S_SIZE);
	HWND intimeEditBox = GetDlgItem(hDlg, IDC_E_S_INTIME);
	HWND classEditBox = GetDlgItem(hDlg, IDC_E_S_CLASS);
	HWND buildingEditBox = GetDlgItem(hDlg, IDC_E_S_BUILDING);
	HWND roomEditBox = GetDlgItem(hDlg, IDC_E_S_ROOM);
	HWND telEditBox = GetDlgItem(hDlg, IDC_E_S_TEL);
	switch (message)
	{
	case WM_INITDIALOG:{
		while (building->nextBuilding != NULL){
			building = building->nextBuilding;
			student = building->firstStudent;
			while (student->nextStudent != NULL){
				student = student->nextStudent;
				if (strcmp(student->id, condition) == 0){
					setDataToEditBox(idEditBox, student->id);
					setDataToEditBox(nameEditBox, student->name);
					USES_CONVERSION;
					setDataToEditBox(genderEditBox, T2A(charToLPWSTR(student->gender)));
					setDataToEditBox(birthEditBox, student->birth);
					setDataToEditBox(categoryEditBox, student->category);
					setDataToEditBox(sizeEditBox, intToString(student->size));
					setDataToEditBox(intimeEditBox, student->inTime);
					setDataToEditBox(classEditBox, student->clazz);
					setDataToEditBox(buildingEditBox, student->building);
					setDataToEditBox(roomEditBox, student->room);
					setDataToEditBox(telEditBox, student->tel);
				}
			}
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_E_S_OK:{
			char *idInfo = (char*)malloc(sizeof(char) * 6);
			strcpy(idInfo, getDataFromEditBox(idEditBox, 5));
			char *nameInfo = (char*)malloc(sizeof(char) * 13);
			strcpy(nameInfo, getDataFromEditBox(nameEditBox, 12));
			char *genderInfo = (char*)malloc(sizeof(char) * 3);
			strcpy(genderInfo, getDataFromEditBox(genderEditBox, 2));
			char *birthInfo = (char*)malloc(sizeof(char) * 13);
			strcpy(birthInfo, getDataFromEditBox(birthEditBox, 12));
			char *categoryInfo = (char*)malloc(sizeof(char) * 16);
			strcpy(categoryInfo, getDataFromEditBox(categoryEditBox, 15));
			char *sizeInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(sizeInfo, getDataFromEditBox(sizeEditBox, 20));
			char *intimeInfo = (char*)malloc(sizeof(char) * 9);
			strcpy(intimeInfo, getDataFromEditBox(intimeEditBox, 8));
			char *classInfo = (char*)malloc(sizeof(char) * 11);
			strcpy(classInfo, getDataFromEditBox(classEditBox, 10));
			char *buildingInfo = (char*)malloc(sizeof(char) * 6);
			strcpy(buildingInfo, getDataFromEditBox(buildingEditBox, 5));
			char *roomInfo = (char*)malloc(sizeof(char) * 6);
			strcpy(roomInfo, getDataFromEditBox(roomEditBox, 5));
			char *telInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(telInfo, getDataFromEditBox(telEditBox, 20));
			if (strlen(idInfo) == 0 || strlen(nameInfo) == 0 || strlen(genderInfo) == 0 ||
				strlen(birthInfo) == 0 || strlen(categoryInfo) == 0 || strlen(sizeInfo) == 0 ||
				strlen(intimeInfo) == 0 || strlen(classInfo) == 0 || strlen(buildingInfo) == 0 ||
				strlen(roomInfo) == 0 || strlen(telInfo) == 0){
				MessageBox(hDlg, L"请填完所有的数据", L"提示", MB_OK);
			}
			else{
				while (building->nextBuilding != NULL){
					building = building->nextBuilding;
					student = building->firstStudent;
					while (student->nextStudent != NULL){
						student = student->nextStudent;
						if (strcmp(student->id, condition) == 0){
							strcpy(student->id, idInfo);
							strcpy(student->name, nameInfo);
							student->gender = genderInfo[0];
							strcpy(student->birth, birthInfo);
							strcpy(student->category, categoryInfo);
							student->size = atoi(sizeInfo);
							strcpy(student->inTime, intimeInfo);
							strcpy(student->clazz, classInfo);
							strcpy(student->building, buildingInfo);
							strcpy(student->room, roomInfo);
							strcpy(student->tel, telInfo);
							MessageBox(hDlg, L"修改成功", L"提示", MB_OK);
							EndDialog(hDlg, LOWORD(wParam));
						}
					}
				}
			}
			break;
		}
		case IDC_E_S_CANCEL:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		}
		break;
	}
	}
	return (INT_PTR)FALSE;
}