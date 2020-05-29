#pragma once
#include "framework.h"
#include "Subject.h"


typedef struct Student {
	char Name[60];
	unsigned int Stud_Code;
	int Grade;
	double prevScore;
	int Applysub[3];
	subject* cursor; 
	
}student;