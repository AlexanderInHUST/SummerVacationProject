#include "stdafx.h"
#include "SummerVacationProject.h"

// insertStudentDataProc函数介绍
// 功能：控制关于插入学生信息对话框里面的一切活动
// 返回值：对话框的结果，用于windows的某些判断


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
			HWND birthYearEditBox = GetDlgItem(hDlg, IDC_I_S_BIRTH_YEAR);
			HWND birthMonthEditBox = GetDlgItem(hDlg, IDC_I_S_BIRTH_MONTH);
			HWND birthDayEditBox = GetDlgItem(hDlg, IDC_I_S_BIRTH_DAY);
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
			char *birthInfo = (char*)malloc(sizeof(char) * 13);
			char *birthYearInfo = (char*)malloc(sizeof(char) * 5);
			char *birthMonthInfo = (char*)malloc(sizeof(char) * 5);
			char *birthDayInfo = (char*)malloc(sizeof(char) * 5);
			strcpy(birthYearInfo, getDataFromEditBox(birthYearEditBox, 5));
			strcpy(birthMonthInfo, getDataFromEditBox(birthMonthEditBox, 5));
			strcpy(birthDayInfo, getDataFromEditBox(birthDayEditBox, 5));
			char *categoryInfo = (char*)malloc(sizeof(char) * 16);
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
			sprintf(birthInfo, "%s/%s/%s", birthYearInfo, birthMonthInfo, birthDayInfo);
			if (strlen(idInfo) == 0 || strlen(nameInfo) == 0 || (IsDlgButtonChecked(hDlg, IDC_I_S_MALE) == false && IsDlgButtonChecked(hDlg, IDC_I_S_FEMALE) == false) ||
				strlen(birthInfo) == 0 || (IsDlgButtonChecked(hDlg, IDC_I_S_TECHNICAL) == false && IsDlgButtonChecked(hDlg, IDC_I_S_UNIVERSITY) == false && IsDlgButtonChecked(hDlg, IDC_I_S_POSTGRADUATE) == false && IsDlgButtonChecked(hDlg, IDC_I_S_MASTER) == false) || strlen(sizeInfo) == 0 ||
				strlen(intimeInfo) == 0 || strlen(classInfo) == 0 || strlen(buildingInfo) == 0 ||
				strlen(roomInfo) == 0 || strlen(telInfo) == 0){
				MessageBox(hDlg, L"请填完所有的数据", L"提示", MB_OK);
			}
			else{
				if (queryStudentById(idInfo, head) != NULL){
					MessageBox(hDlg, L"此学号已被登记", L"提示", MB_OK);
				} 
				else{
					bool found = false;
					genderInfo = IsDlgButtonChecked(hDlg, IDC_I_S_MALE) ? "M" : "F";
					if (IsDlgButtonChecked(hDlg, IDC_I_S_TECHNICAL)){
						categoryInfo = "专科";
					}
					else if (IsDlgButtonChecked(hDlg, IDC_I_S_UNIVERSITY)){
						categoryInfo = "本科";
					}
					else if (IsDlgButtonChecked(hDlg, IDC_I_S_POSTGRADUATE)){
						categoryInfo = "硕士";
					}
					else{
						categoryInfo = "博士";
					}
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