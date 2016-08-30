#include "stdafx.h"
#include "SummerVacationProject.h"

// editStudentDataProc��������
// ���ܣ����ƹ��ڱ༭ѧ���Ի��������һ�л
// ����ֵ���Ի���Ľ��������windows��ĳЩ�ж�

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
	HWND birthYearEditBox = GetDlgItem(hDlg, IDC_E_S_BIRTH_YEAR);
	HWND birthMonthEditBox = GetDlgItem(hDlg, IDC_E_S_BIRTH_MONTH);
	HWND birthDayEditBox = GetDlgItem(hDlg, IDC_E_S_BIRTH_DAY);
	HWND sizeEditBox = GetDlgItem(hDlg, IDC_E_S_SIZE);
	HWND intimeEditBox = GetDlgItem(hDlg, IDC_E_S_INTIME_YEAR);
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
					if (student->gender == 'M'){
						CheckRadioButton(hDlg, IDC_E_S_MALE, IDC_E_S_FEMALE, IDC_E_S_MALE);
					}
					else{
						CheckRadioButton(hDlg, IDC_E_S_MALE, IDC_E_S_FEMALE, IDC_E_S_FEMALE);
					}
					setDataToEditBox(birthYearEditBox, strtok(student->birth, "/"));
					setDataToEditBox(birthMonthEditBox, strtok(NULL, "/"));
					setDataToEditBox(birthDayEditBox, strtok(NULL, "/"));
					if (strcmp(student->category, "ר��") == 0){
						CheckRadioButton(hDlg, IDC_E_S_TECHNICAL, IDC_E_S_MASTER, IDC_E_S_TECHNICAL);
					}
					else if (strcmp(student->category, "����") == 0){
						CheckRadioButton(hDlg, IDC_E_S_TECHNICAL, IDC_E_S_MASTER, IDC_E_S_UNIVERSITY);
					}
					else if (strcmp(student->category, "˶ʿ") == 0){
						CheckRadioButton(hDlg, IDC_E_S_TECHNICAL, IDC_E_S_MASTER, IDC_E_S_POSTGRADUATE);
					}
					else{
						CheckRadioButton(hDlg, IDC_E_S_TECHNICAL, IDC_E_S_MASTER, IDC_E_S_MASTER);
					}
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
			char *intimeInfo = (char*)malloc(sizeof(char) * 10);
			strcpy(intimeInfo, getDataFromEditBox(intimeEditBox, 9));
			char *classInfo = (char*)malloc(sizeof(char) * 11);
			strcpy(classInfo, getDataFromEditBox(classEditBox, 10));
			char *buildingInfo = (char*)malloc(sizeof(char) * 6);
			strcpy(buildingInfo, getDataFromEditBox(buildingEditBox, 5));
			char *roomInfo = (char*)malloc(sizeof(char) * 6);
			strcpy(roomInfo, getDataFromEditBox(roomEditBox, 5));
			char *telInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(telInfo, getDataFromEditBox(telEditBox, 20));
			sprintf(birthInfo, "%s/%s/%s", birthYearInfo, birthMonthInfo, birthDayInfo);
			if (strlen(idInfo) == 0 || strlen(nameInfo) == 0 || (IsDlgButtonChecked(hDlg, IDC_E_S_MALE) == false && IsDlgButtonChecked(hDlg, IDC_E_S_FEMALE) == false) ||
				strlen(birthInfo) == 0 || (IsDlgButtonChecked(hDlg, IDC_E_S_TECHNICAL) == false && IsDlgButtonChecked(hDlg, IDC_E_S_UNIVERSITY) == false && IsDlgButtonChecked(hDlg, IDC_E_S_POSTGRADUATE) == false && IsDlgButtonChecked(hDlg, IDC_E_S_MASTER) == false) || strlen(sizeInfo) == 0 ||
				strlen(intimeInfo) == 0 || strlen(classInfo) == 0 || strlen(buildingInfo) == 0 ||
				strlen(roomInfo) == 0 || strlen(telInfo) == 0){
				MessageBox(hDlg, L"���������е�����", L"��ʾ", MB_OK);
			}
			else{
				bool done = false;
				genderInfo = IsDlgButtonChecked(hDlg, IDC_E_S_MALE) ? "M" : "F";
				if (IsDlgButtonChecked(hDlg, IDC_E_S_TECHNICAL)){
					categoryInfo = "ר��";
				}
				else if (IsDlgButtonChecked(hDlg, IDC_E_S_UNIVERSITY)){
					categoryInfo = "����";
				}
				else if (IsDlgButtonChecked(hDlg, IDC_E_S_POSTGRADUATE)){
					categoryInfo = "˶ʿ";
				}
				else{
					categoryInfo = "��ʿ";
				}
				while (building->nextBuilding != NULL){
					building = building->nextBuilding;
					student = building->firstStudent;
					if (done)
						break;
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
							if (strcmp(buildingInfo, student->building) != 0){
								struct Building *tempHead = getHead();
								struct Building *tempBuilding = tempHead;
								struct Student *tempStudent;
								struct Student *copyStudent;

								// ���ѧ����Ϣ�е�����¥���༭�ˣ���ô��Ҫ���¸ı�����ṹ
								// ��Ҫ��ԭ����ѧ������ɾ����������һ������¥�������������
								// �˴������Ż�������ʹ����д�õĺ������в��������ø���

								while (tempBuilding->nextBuilding != NULL){
									tempBuilding = tempBuilding->nextBuilding;
									if (strcmp(tempBuilding->num, student->building) == 0){
										tempStudent = tempBuilding->firstStudent;
										while (tempStudent->nextStudent != NULL){
											if (strcmp(tempStudent->nextStudent->id, student->id) == 0){
												copyStudent = tempStudent->nextStudent;
												tempStudent->nextStudent = copyStudent->nextStudent;
												tempStudent->nextRec = copyStudent->nextRec;
												copyStudent->nextStudent = NULL;
												copyStudent->nextRec = getID();
												break;
											}
											tempStudent = tempStudent->nextStudent;
										}
									}
								}
								tempBuilding = tempHead;
								while (tempBuilding->nextBuilding != NULL){
									tempBuilding = tempBuilding->nextBuilding;
									if (strcmp(tempBuilding->num, buildingInfo) == 0){
										tempStudent = tempBuilding->firstStudent;
										while (tempStudent->nextStudent != NULL){
											tempStudent = tempStudent->nextStudent;
										}
										tempStudent->nextStudent = copyStudent;
										tempStudent->nextRec = copyStudent->rec;
									}
								}
							}
							strcpy(student->building, buildingInfo);
							strcpy(student->room, roomInfo);
							strcpy(student->tel, telInfo);
							MessageBox(hDlg, L"�޸ĳɹ�", L"��ʾ", MB_OK);
							EndDialog(hDlg, LOWORD(wParam));
							done = true;
							break;
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