#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK insertStudentDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	struct Building *head = getHead();
	struct Building *building;
	struct Student *student;
	building = head;
	switch (message)
	{
	case WM_INITDIALOG:{
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_I_S_OK:{
			HWND idEditBox = GetDlgItem(hDlg, IDC_I_S_ID);
			HWND nameEditBox = GetDlgItem(hDlg, IDC_I_S_NAME);
			HWND genderEditBox = GetDlgItem(hDlg, IDC_I_S_GENDER);
			HWND birthEditBox = GetDlgItem(hDlg, IDC_I_S_BIRTH);
			HWND categoryEditBox = GetDlgItem(hDlg, IDC_I_S_CATEGORY);
			HWND sizeEditBox = GetDlgItem(hDlg, IDC_I_S_SIZE);
			HWND intimeEditBox = GetDlgItem(hDlg, IDC_I_S_INTIME);
			HWND classEditBox = GetDlgItem(hDlg, IDC_I_S_CLASS);
			HWND buildingEditBox = GetDlgItem(hDlg, IDC_I_S_BUILDING);
			HWND roomEditBox = GetDlgItem(hDlg, IDC_I_S_ROOM);
			HWND telEditBox = GetDlgItem(hDlg, IDC_I_S_TEL);
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
				bool found = false;
				while (building->nextBuilding != NULL){
					building = building->nextBuilding;
					if (strcmp(building->num, buildingInfo) == 0){
						found = true;
						student = building->firstStudent;
						while (student->nextStudent != NULL){
							student = student->nextStudent;
						}
						struct Student *newStudent = createStudentData(idInfo, nameInfo, genderInfo[0], birthInfo, categoryInfo, atoi(sizeInfo), intimeInfo, classInfo, buildingInfo, roomInfo, telInfo, NULL, NULL, student->nextRec);
						student->nextStudent = newStudent;
						MessageBox(hDlg, L"添加成功", L"提示", MB_OK);
						EndDialog(hDlg, LOWORD(wParam));
					}
				}
				if (!found){
					MessageBox(hDlg, L"没有所输入的宿舍楼信息", L"提示", MB_OK);
				}
			}
			break;
		}
		case IDC_I_S_CANCEL:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		}
		break;
	}
	}
	return (INT_PTR)FALSE;
}