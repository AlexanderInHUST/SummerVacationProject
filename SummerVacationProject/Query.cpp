#include "stdafx.h"
#include "SummerVacationProject.h"

// queryBuilding函数介绍
// 功能：搜索楼号是num的宿舍楼信息
// 返回值：得到的地址或者NULL

struct Building* queryBuilding(char num[5], struct Building *head){
	struct Building *p = head;
	while (p->nextBuilding != NULL){
		p = p->nextBuilding;
		if (strcmp(p->num, num) == 0){
			return p;
		}
	}
	return NULL;
}

// queryStudentById函数介绍
// 功能：搜索学号是id的学生信息
// 返回值：得到的地址或者NULL

struct Student* queryStudentById(char id[12], struct Building *head){
	struct Building *building = head;
	struct Student *student;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			if (strcmp(student->id, id) == 0){
				return student;
			}
		}
	}
	return NULL;
}

// queryStudentById函数介绍
// 功能：搜索姓名是name的学生信息，并且将得到的数据构成一个链表
// 返回值：得到链表的头结点的地址或者NULL

struct Student* queryStudentListByName(char name[12], struct Building *head){
	struct Building *building = head;
	struct Student *student;
	struct Student *studentByName;
	struct Student *headStudentByName;
	char innerName[12];
	bool exist = false;
	strcpy(innerName, name);
	studentByName = (struct Student*)malloc(sizeof(struct Student));
	headStudentByName = studentByName;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			if (strcmp(student->name, innerName) == 0){
				exist = true;
				struct Student *temp =
					createStudentData(student->id, student->name, student->gender, student->birth, student->category, student->size, student->inTime, student->clazz, student->building, student->room, student->tel, student->firstExpenses, NULL, -1);
				studentByName->nextStudent = temp;
				studentByName = studentByName->nextStudent;
			}
		}
	}
	return (exist == false) ? NULL : headStudentByName;
}

