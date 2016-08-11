#include "stdafx.h"
#include "SummerVacationProject.h"

struct Building{
	char num[5];
	char administrator[20];
	char tel[20];
	short rooms;
	short beds;
	float cost;
	struct Student *firstStudent;
	struct Building *nextBuilding;

	int rec;
	int nextRec;
	int firstStudentRec;
};

struct Building* createBuildingData(
	char num[5],
	char administrator[20],
	char tel[20],
	short rooms,
	short beds,
	float cost,
	struct Student *firstStudent,
	struct Building *nextBuilding,
	int rec);