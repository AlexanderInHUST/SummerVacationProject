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