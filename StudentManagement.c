#include "StudentManagement.h"
#include "StudentDatabase.h"
#include <stdio.h>
#include"conio.h"
#include <string.h>
#include <stdlib.h>
// external data types
/////////////////////////////////////////
//extern int i;
extern int NUM_OF_STUDENT; // Change this i into number of student in your progrm
extern student st[STUDNET_NUM];
//extern student st;



//////////////////////////////////////////////////////////////////

//function definetion
/////////////////////////////////////////////////////////

// Function to add the student
void add_student()
{
	// open the file to write data into it
	FILE *fp = fopen("StudentDB.txt", "a");
	// if the file is not found, exit
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	// in order to skip the first line of the file
	fseek (fp, 0, SEEK_END);
    int size = ftell(fp);

	// to add headers if the file is empty
    if (0 == size) {
		fprintf(fp, "First, Last, Roll, CGPA, NumCourses, CourseID\n");
    }

	char fname[STUDNET_NUM];
	char lname[STUDNET_NUM];
	int roll = 0;
	float CGPA = 0.0;
	int NumOfCourses = 0;
	int cid[COURSE_NUM];

	printf("Add the Students Details\n");
	printf("-------------------------\n");
	printf("Enter the first name of student\n");
    scanf("%s", &fname);
	printf("Enter the last name of student\n");
	scanf("%s", &lname);
	printf("Enter the Roll Number\n");
	scanf("%d", &roll);
	printf("Enter the CGPA you obtained\n");
	scanf("%f", &CGPA);
	printf("Enter the number of courses:\n");
	scanf("%d", &NumOfCourses);
	printf("Enter the course ID of each course\n");
	for (int j = 0; j < NumOfCourses; j++) {
		scanf("%d", &cid[j]);
	}

	fprintf(fp, "%s,", fname);
	fprintf(fp, "%s,", lname);
	fprintf(fp, "%d,", roll);
	fprintf(fp, "%f,", CGPA);
	fprintf(fp, "%d,", NumOfCourses);

	for (int j = 0; j < NumOfCourses; j++)
	{
		fprintf(fp, "%d|", cid[j]);
	}
	fprintf(fp, "\n");
	fclose(fp);

}

void find_rl()
{
	int TRoll;
	printf("Enter the Roll Number of the student\n");
	scanf("%d", &TRoll);

	FILE *fp = fopen("StudentDB.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}


	char line[256];
	fgets(line, sizeof(line), fp);
	while (fgets(line, sizeof(line), fp))
	{
		char * fName = strtok(line, ",");
		char * lName = strtok(NULL, ",");
		char * roll = strtok(NULL, ",");
		char * CGPA = strtok(NULL, ",");
		char * NumOfCourses = strtok(NULL, ",");
		if(TRoll == atoi(roll))
		{
			printf("The Students Details are\n");
			printf("The First name is %s\n", fName);
			printf("The Last name is %s\n", lName);
			printf("The CGPA is %s\n", CGPA);
			printf("The Roll Number is %s\n", roll);
			printf("The course ID is:");
			for (int i = 0; i < atoi(NumOfCourses); i++)
			{
				char * cid = strtok(NULL, "|");
				printf("%s\n",cid);
			}
		}

	}

	fclose(fp);
}

void find_fn()
{
	char stname[50];
	printf("Enter the First Name of the student\n");
	scanf("%s", stname);

	FILE *fp = fopen("StudentDB.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	char line[256];
	fgets(line, sizeof(line), fp);
	while (fgets(line, sizeof(line), fp))
	{
		char * fName = strtok(line, ",");
		char * lName = strtok(NULL, ",");
		char * roll = strtok(NULL, ",");
		char * CGPA = strtok(NULL, ",");
		char * NumOfCourses = strtok(NULL, ",");
		if(!strcmp(fName, stname))
		{
			printf("The Students Details are\n");
			printf("The First name is %s\n",fName);
			printf("The Last name is %s\n",lName);
			printf("The CGPA is %s\n",CGPA);
			printf("The Roll Number is %s\n",roll);
			printf("The courses:");
			for (int i = 0; i < atoi(NumOfCourses); i++)
			{
				char * cid = strtok(NULL, "|");
				printf("%s",cid);
			}
		}

	}

	fclose(fp);
}

void find_c()
{
	int Tcid;
	printf("Enter the course ID \n");
	scanf("%d", &Tcid);

	FILE *fp = fopen("StudentDB.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	char line[256];
	fgets(line, sizeof(line), fp);
	while (fgets(line, sizeof(line), fp))
	{
		char * fName = strtok(line, ",");
		char * lName = strtok(NULL, ",");
		char * roll = strtok(NULL, ",");
		char * CGPA = strtok(NULL, ",");
		char * NumOfCourses = strtok(NULL, ",");
		int coursesID[COURSE_NUM];
		int found = 0;
		for (int i = 0; i < atoi(NumOfCourses); i++)
		{
			char * cid = strtok(NULL, "|");
			coursesID[i] = atoi(cid);
			if (Tcid == coursesID[i])
			{
				found = 1;
			}
		}
		if (found)
		{
			printf("The Students Details are\n");
			printf("The First name is %s\n",fName);
			printf("The Last name is %s\n",lName);
			printf("The CGPA is %s\n",CGPA);
			printf("The Roll number is %s\n",roll);
			printf("Courses:\n");
			for (int i = 0; i < atoi(NumOfCourses); i++)
			{
				printf("%d\n", coursesID[i]);
			}
		}
	}

	fclose(fp);

}

void tot_s()
{
	FILE *fp = fopen("StudentDB.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	char line[256];
	int counter = 0;
	fgets(line, sizeof(line), fp);
	while (fgets(line, sizeof(line), fp))
	{
		counter++;
	}
	printf("The total number of students is %d\n",counter);
	fclose(fp);

}

void del_s()
{
	int TID;
	printf("Enter the Roll Number of the student to delete\n");
	scanf("%d", &TID);

	FILE *fp = fopen("StudentDB.txt", "r");
	FILE * temp = fopen("temp.txt","a");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	char line[256];
	fgets(line, sizeof(line), fp);
	fputs(line,temp);
	while (fgets(line, sizeof(line), fp))
	{
		char tempLine[256];
		strcpy(tempLine, line);
		char * fName = strtok(line, ",");
		char * lName = strtok(NULL, ",");
		char * roll = strtok(NULL, ",");
		char * CGPA = strtok(NULL, ",");
		char * NumOfCourses = strtok(NULL, ",");
		if(atoi(roll) != TID)
		{
			fputs(tempLine,temp);
		}

	}

	fclose(fp);
	fclose(temp);
	remove("StudentDB.txt");
	rename("temp.txt","StudentDB.txt");
}

void up_s()
{
	printf("Enter the Roll Number of the student to update\n");
	int TID;
	scanf("%d", &TID);
	FILE *fp = fopen("StudentDB.txt", "r");
	FILE * temp = fopen("temp.txt","a");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	char line[256];
	fgets(line, sizeof(line), fp);
	fputs(line,temp);
	while (fgets(line, sizeof(line), fp))
	{
		char tempLine[256];
		strcpy(tempLine, line);
		char * fName = strtok(line, ",");
		char * lName = strtok(NULL, ",");
		char * roll = strtok(NULL, ",");
		char * CGPA = strtok(NULL, ",");
		int NumOfCourses = atoi(strtok(NULL, ","));
		int coursesID[COURSE_NUM];
		for (int i = 0; i < NumOfCourses; i++) {
			coursesID[i] = atoi(strtok(NULL, "|"));
		}
		char updatedFirstName[255];
		char updatedLastName[255];
		char updatedRoll[255];
		char updatedCGPA[255];
		strcpy(updatedFirstName, fName);
		strcpy(updatedLastName, lName);
		strcpy(updatedRoll, roll);
		strcpy(updatedCGPA, CGPA);

		printf("Choose the field you want to update:\n");
		if (atoi(roll) == TID) {
			printf( "1. first name\n"
					"2. last name\n"
					"3. roll no.\n"
					"4. CGPA\n"
					"5. courses\n");
			//int choice;
			//printf("%d,", roll);

			int newNumOfCourses;
			//scanf("%d", &choice);

			int choice;
			scanf("%d", &choice);

			switch (choice) {
			case 1:
				printf("Enter the new first name: \n");
				scanf("%s", updatedFirstName);
				break;
			case 2:
				printf("Enter the new last name: \n");
				scanf("%s", updatedLastName);
				break;
			case 3:
				printf("Enter the new roll number: \n");
				scanf("%s", updatedRoll);
				break;
			case 4:
				printf("Enter the new CGPA: \n");
				scanf("%s", updatedCGPA);
				break;
			case 5:
				printf("Enter the new courses size \n");
				scanf("%d", &newNumOfCourses);
				printf("Enter the new courses ID \n");
				for (int i = 0; i < newNumOfCourses; i++) {
					int courseID;
					scanf("%d", &courseID);
					coursesID[NumOfCourses+i] = courseID;
				}
				NumOfCourses += newNumOfCourses;
				break;
			}
			fprintf(temp, "%s,", updatedFirstName);
			fprintf(temp, "%s,", updatedLastName);
			fprintf(temp, "%s,", updatedRoll);
			fprintf(temp, "%s,", updatedCGPA);
			fprintf(temp, "%d,", NumOfCourses);
			for (int i = 0; i < NumOfCourses; i++) {
				fprintf(temp, "%d|", coursesID[i]);
			}
			printf("UPDATED SUCCESSFULLY.\n");
		}
		else{
			fputs(tempLine,temp);
		}
	}

	fclose(fp);
	fclose(temp);
	remove("StudentDB.txt");
	rename("temp.txt","StudentDB.txt");
}
