#include "stdafx.h"
#include "SummerVacationProject.h"

// deleteBuildingData��������
// ���ܣ�ɾ����hListView�б�ѡ�е�����¥���ݽ�㣬��������������������
// ����ֵ����

void deleteBuildingData(struct Building *head, HWND hListView, HWND hWND){
	struct Building *building = head;
	int mark = ListView_GetSelectionMark(hListView);
	LPTSTR num = (LPTSTR)malloc(sizeof(LPTCH) * 6);
	ListView_GetItemText(hListView, mark, 0, num, 6);
	USES_CONVERSION;
	char *numString = (char*)malloc(sizeof(char) * 6);
	numString = T2A(num);
	
	//��ѡ�е������л��ÿ������¥��Ψһ��ʶnum��Ȼ����������������ɾ��
	
	bool found = false;
	if (mark == -1){
		MessageBox(hWND, L"����ѡ��һ����Ϣ", L"�쳣", MB_OK);
		return;
	}
	while (building->nextBuilding != NULL){
		if (strcmp(building->nextBuilding->num, numString) == 0){
			found = true;
			struct Building *temp = building->nextBuilding->nextBuilding;
			building->nextRec = building->nextBuilding->nextRec;
			free(building->nextBuilding);
			building->nextBuilding = temp;
			MessageBox(hWND, L"ɾ���ɹ�", L"��ʾ", MB_OK);
			return;
		}
		building = building->nextBuilding;
	}
	if (!found){
		MessageBox(hWND, L"�쳣����δ�ҵ���Ӧ¥��Ϣ", L"�쳣", MB_OK);
	}
}

// deleteStudentData��������
// ���ܣ�ɾ����hListView�б�ѡ�е�ѧ�����ݽ�㣬��������������������
// ����ֵ����

void deleteStudentData(struct Building *head, HWND hListView, HWND hWND){
	struct Building *building = head;
	struct Student *student;
	int mark = ListView_GetSelectionMark(hListView);
	LPTSTR id = (LPTSTR)malloc(sizeof(LPTCH) * 13);
	ListView_GetItemText(hListView, mark, 0, id, 13);
	USES_CONVERSION;
	char *idString = (char*)malloc(sizeof(char) * 13);
	idString = T2A(id);

	//��ѡ�е������л��ÿ��ѧ����Ψһ��ʶid��Ȼ����������������ɾ��
	
	bool found = false;
	if (mark == -1){
		MessageBox(hWND, L"����ѡ��һ����Ϣ", L"�쳣", MB_OK);
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
				MessageBox(hWND, L"ɾ���ɹ�", L"��ʾ", MB_OK);
				return;
			}
			student = student->nextStudent;
		}
	}
	if (!found){
		MessageBox(hWND, L"�쳣����δ�ҵ���Ӧ¥��Ϣ", L"�쳣", MB_OK);
	}
}

// deleteExpensesData��������
// ���ܣ�ɾ����hListView�б�ѡ�еĽɷ����ݽ�㣬�����������������������ڽɷ�����û��Ψһ��ʶ��ֻ��ȫ��һһ��Ӧ������
// ����ֵ����

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
	
	//��ѡ�е������л��ÿ���ɷ����ݵ����б�ʶ��Ȼ����������������ɾ��
	
	bool found = false;
	if (mark == -1){
		MessageBox(hWND, L"����ѡ��һ����Ϣ", L"�쳣", MB_OK);
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
					MessageBox(hWND, L"ɾ���ɹ�", L"��ʾ", MB_OK);
					return;
				}
				expenses = expenses->nextExpenses;
			}
		}
	}
	if (!found){
		MessageBox(hWND, L"�쳣����δ�ҵ���Ӧ¥��Ϣ", L"�쳣", MB_OK);
	}
}