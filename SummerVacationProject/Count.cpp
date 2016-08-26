#include "stdafx.h"
#include "SummerVacationProject.h"

// 为了计算欠费信息，要给一个今年的年份，才能计算住宿的年份

#define NOW_YEAR 2016

// countArrearage函数介绍
// 功能：传入一个学生数据，计算这个学生欠费金额多少（计算方法：（当前年份 - 入学年份 + 1）* 学生住宿的宿舍楼的年缴费 ）
// 返回值：欠费的金额（如果没有欠费，返回 -100，以避免浮点数不能直接比较相等而发生的问题）

float countArrearage(struct Student *student){
	struct Building *head = getHead();
	struct Building *building;
	struct Expenses *expenses;
	float arrearage = -1;
	float cost;
	float expensesAmount = 0;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		if (strcmp(building->num, student->building) == 0){
			cost = (NOW_YEAR - atoi(strtok(student->inTime, "/")) + 1) * building->cost;
			expenses = student->firstExpenses;
			while (expenses->nextExpenses != NULL){
				expenses = expenses->nextExpenses;
				expensesAmount = expensesAmount + expenses->cost;
			}
			arrearage = cost - expensesAmount;
		}
	}
	return ((int)arrearage == 0) ? -100 : arrearage;
}

// countDormitory函数介绍
// 功能：传入一个宿舍楼信息，统计该宿舍楼住的人数
// 返回值：该宿舍楼住的人数

int countDormitory(struct Building *building){
	int num = 0;
	struct Student *student = building->firstStudent;
	while (student->nextStudent != NULL){
		student = student->nextStudent;
		num++;
	}
	return num;
}

// countGender函数介绍
// 功能：传入一个学生的类型（本科之类的），计算这个类型中的学生的男女比例
// 返回值：该类型男生的比例

float countGender(char *size){
	float maleWeight;
	int amount = 0;
	int male = 0;
	bool found = false;
	struct Building *head = getHead();
	struct Building *building;
	struct Student *student;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			if (strcmp(student->category, size) == 0){
				found = true;
				amount++;
				if (student->gender == 'M'){
					male++;
				}
			}
		}
	}
	return (found) ? (float)male / (float)amount : -100;
}

// countIncome函数介绍
// 功能：传入一个有效值只有楼号的宿舍楼信息，计算这个宿舍楼的年收入
// 返回值：该宿舍楼年收入

float countIncome(struct Building *buildingInfo){
	struct Building *head = getHead();
	struct Building *building;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		if (strcmp(buildingInfo->num, building->num) == 0){
			return countDormitory(buildingInfo) * building->cost;
		}
	}
}

// countClass函数介绍
// 功能：获得一个链表，以头结点为开头，链表中包含着各个班级的基础信息
// 返回值：该链表的头结点的地址

struct CountClass* countClass(){
	struct CountClass* classHead;
	struct CountClass* countClass;
	struct Building* head;
	struct Building* building;
	struct Student* student;
	head = getHead();
	classHead = (struct CountClass*)malloc(sizeof(struct CountClass));
	classHead->next = NULL;
	countClass = classHead;
	building = head;
	while (building->nextBuilding != NULL){
		building = building->nextBuilding;
		student = building->firstStudent;
		while (student->nextStudent != NULL){
			student = student->nextStudent;
			countClass = classHead;
			bool found = false;
			while (countClass->next != NULL){
				countClass = countClass->next;
				if (strcmp(countClass->clazz, student->clazz) == 0){
					found = true;
					countClass->num++;
					if (countArrearage(student) != -100){
						countClass->arrearage++;
					}
				}
			}
			if (!found){
				struct CountClass *temp = (struct CountClass*)malloc(sizeof(struct CountClass));
				strcpy(temp->clazz, student->clazz);
				temp->num = 1;
				temp->arrearage = (countArrearage(student) == -100) ? 0 : 1;
				countClass->next = temp;
				countClass = countClass->next;
				countClass->next = NULL;
			}
		}
	}
	return classHead;
}