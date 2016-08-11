#include "stdafx.h"
#include "SummerVacationProject.h"

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
	newBuilding->beds = beds;
	newBuilding->cost = cost;
	newBuilding->firstStudent = firstStudent;
	newBuilding->nextBuilding = newBuilding;
	newBuilding->rec = rec;
	newBuilding->nextRec = getID();
	newBuilding->firstStudentRec = getID();
	return newBuilding;
}