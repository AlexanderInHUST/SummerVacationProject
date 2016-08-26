#include "stdafx.h"
#include "SummerVacationProject.h"

// createBuildingData函数介绍
// 功能：分配出一个按照参数传入的值赋值好了的寝室楼数据的内存，然后返回内存的地址
// 返回值：创建好了的内存的地址

struct Building* createBuildingData(
	char num[5],
	char administrator[20],
	char tel[20],
	short rooms,
	short beds,
	float cost,
	struct Student *firstStudent,
	struct Building *nextBuilding,
	int rec){

	struct Building *newBuilding;

	newBuilding = (struct Building*)malloc(sizeof(struct Building));

	strcpy(newBuilding->num, num);
	strcpy(newBuilding->administrator, administrator);
	strcpy(newBuilding->tel, tel);
	newBuilding->rooms = rooms;
	newBuilding->beds = rooms * beds;
	newBuilding->cost = cost;
	// 如果firstStudent是NULL，那么就创建一个新的学生数据，并作为头结点，放在firstStudent下面
	if (firstStudent == NULL){
		newBuilding->firstStudentRec = getID();
		newBuilding->firstStudent = createStudentData("head", "head", 'H', "head", "head", -1, "head", "head", "head", " head", "head", NULL, NULL, newBuilding->firstStudentRec);
		newBuilding->firstStudent->nextStudent = NULL;
	}
	else{
		newBuilding->firstStudent = firstStudent;
		newBuilding->firstStudentRec = firstStudent->rec;
	}
	if (nextBuilding == NULL){
		newBuilding->nextRec = getID();
	}
	else{
		newBuilding->nextRec = nextBuilding->rec;
	}
	newBuilding->nextBuilding = nextBuilding;
	newBuilding->rec = rec;
	return newBuilding;
}