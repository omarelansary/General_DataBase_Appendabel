#include  "EmployeeManagement.h"
#include  "EmployeeDatabase.h"
#include <stdio.h>
#include"conio.h"
#include <string.h>
#include <stdlib.h>

// external data types
/////////////////////////////////////////
extern int NUM_OF_FACTORY_EMP; // Change this i into number of employee in your progrm
extern Employee em[EMPLOYEE_NUM];
/////////////////////////////////////////////////////////////////
// 2- Function to add the employee
// 3- Function to find the employee
// by the roll number
// 4- Function to find the employee
// by the first name
// 5- Function to find
// the employee enrolled
// in a particular factory section
// 6- Function t o print the total
// number of employee
// 7- Function to delete a employee
// by the roll number
// 8- Function to update a employee data


//function definetion
/////////////////////////////////////////////////////////

// Function to add the employee
void add_Factory_emp()
{
		// open the file to write data into it
	FILE *fp = fopen("EmployeeDB.txt", "a");
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
		fprintf(fp, "First, Last, Roll, salary, SectionID\n");
    }

	char fname[EMPLOYEE_NUM];
	char lname[EMPLOYEE_NUM];
	int roll = 0;
	int Salary = 0;
	int sid[SECTION_NUM];

	printf("Add the employee Details\n");
	printf("-------------------------\n");
	printf("Enter the first "
		"name of employee\n");
	scanf("%s", &fname);
	printf("Enter the last name"
		" of employee\n");
	scanf("%s", &lname);
	printf("Enter the roll Number\n");
	scanf("%d", &roll);
	printf("Enter the salary "
		"of employee\n");
	scanf("%d", &Salary);
	printf("Enter the Factory section ID"
		" of each section with max of 2 sections if emp is in one section put the second option with 0\n");
	for (int j = 0; j < 2; j++) {
		scanf("%d", &sid[j]);
	}

	fprintf(fp, "%s,", fname);
	fprintf(fp, "%s,", lname);
	fprintf(fp, "%d,", roll);
	fprintf(fp, "%d,", Salary);

	for (int j = 0; j < 2; j++)
	{
		fprintf(fp, "%d|", sid[j]);
	}
	fprintf(fp, "\n");
	fclose(fp);

}

void find_fn_Factory_emp()
{
	char Factoryempfname[50];
	printf("Enter the First Name of the Employee\n");
	scanf("%s", Factoryempfname);

	FILE *fp = fopen("EmployeeDB.txt", "r");

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
		char * Salary = strtok(NULL, ",");
		if(!strcmp(fName, Factoryempfname))
		{
			printf("The Employee Details are\n");
			printf("The First name is %s\n", fName);
			printf("The Last name is %s\n", lName);
			printf("The Salary is %s\n", Salary);
			printf("The Roll Number is %s\n", roll);
			printf("The Section ID is:");
			for (int i = 0; i < 2; i++)
			{
				char * Sid = strtok(NULL, "|");
				printf("%s\n",Sid);
			}
		}

	}

	fclose(fp);
}


// Function to find the employee
// by the roll number
void find_rl_Factory_emp()
{
	int temp;
	printf("Enter the Roll Number of the Employee\n");
	scanf("%d", &temp);

	FILE *fp = fopen("EmployeeDB.txt", "r");
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
		char * Salary = strtok(NULL, ",");
		char * SectionId = strtok(NULL, ",");
		if(temp == atoi(roll))
		{
			printf("The Employee Details are\n");
			printf("The First name is %s\n", fName);
			printf("The Last name is %s\n", lName);
			printf("The Salary is %s\n", Salary);
			printf("The Roll Number is %s\n", roll);
			printf("The Section ID is:");
			for (int i = 0; i < 2; i++)
			{
				char * Sid = strtok(NULL, "|");
				printf("%s\n",Sid);
			}
		}

	}

	fclose(fp);
}

// Function to find
// the employee enrolled
// in a particular factory section
void find_Factory_s()
{
	int id;
	printf("Enter the factory section ID \n");
	scanf("%d", &id);
	int c = 0;

		FILE *fp = fopen("EmployeeDB.txt", "r");
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
		char * salary = strtok(NULL, ",");
		int SectionID[SECTION_NUM];
		int found = 0;
		for (int i = 0; i < 2; i++)
		{
			char * sid = strtok(NULL, "|");
			SectionID[i] = atoi(sid);
			if (id == SectionID[i])
			{
				found = 1;
			}
		}
		if (found)
		{
			printf("The Employee Details are\n");
			printf("The First name is %s\n",fName);
			printf("The Last name is %s\n",lName);
			printf("The Salary is %s\n",salary);
			printf("The Roll number is %s\n",roll);
			printf("Section:\n");
			for (int i = 0; i < 2; i++)
			{
				printf("%d\n", SectionID[i]);
			}
		}
	}

	fclose(fp);

}

// Function to print the total
// number of employee
void tot_Factory_emp()
{
	FILE *fp = fopen("EmployeeDB.txt", "r");
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
	printf("The total number of employees is %d\n",counter);
	fclose(fp);
}

// Function to delete a employee
// by the roll number
void del_Factory_emp()
{
	int a;
	printf("Enter the Roll Number"
		" which you want "
		"to delete\n");
	scanf("%d", &a);

	FILE *fp = fopen("EmployeeDB.txt", "r");
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
		char * Salary = strtok(NULL, ",");
		char * SectionNum= strtok(NULL, ",");
		if(atoi(roll) != a)
		{
			fputs(tempLine,temp);
		}
	}

	fclose(fp);
	fclose(temp);
	remove("EmployeeDB.txt");
	rename("temp.txt","EmployeeDB.txt");

	printf("The Roll Number"
		" is removed Successfully\n");
}

// Function to update a employee data
void up_Factory_emp()
{

	printf("Enter the roll number"
		" to update the entry : ");
	int x;
	scanf("%d", &x);

	FILE *fp = fopen("EmployeeDB.txt", "r");
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
		char * Salary = strtok(NULL, ",");
		int SectionID[SECTION_NUM];
		for (int i = 0; i < 2; i++) {
			SectionID[i] = atoi(strtok(NULL, "|"));
		}
		char updatedFirstName[255];
		char updatedLastName[255];
		char updatedRoll[255];
		char updatedSalary[255];
		strcpy(updatedFirstName, fName);
		strcpy(updatedLastName, lName);
		strcpy(updatedRoll, roll);
		strcpy(updatedSalary, Salary);

   		printf("Choose the field you want to update:\n");
		if (atoi(roll) == x) {
			printf( "1. first name\n"
					"2. last name\n"
					"3. roll no.\n"
					"4. Salary\n"
					"5. Section ID\n");
			int choice;
			printf("%d,", roll);

			int newCoursesNum;
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
				printf("Enter the new Salary: \n");
				scanf("%s", updatedSalary);
				break;
			case 5:
				printf("Enter the new Sections ID \n");
				for (int i = 0; i < 2; i++) {
					int sectionID;
					scanf("%d", &sectionID);
					SectionID[SECTION_NUM+i] = sectionID;
				}

				break;
			}
			fprintf(temp, "%s,", updatedFirstName);
			fprintf(temp, "%s,", updatedLastName);
			fprintf(temp, "%s,", updatedRoll);
			fprintf(temp, "%s,", updatedSalary);

			for (int i = 0; i < 2; i++) {
				fprintf(temp, "%d|", SectionID[i]);
			}
			printf("UPDATED SUCCESSFULLY.\n");
		}
		else{
			fputs(tempLine,temp);
		}
	}

	fclose(fp);
	fclose(temp);
	remove("EmployeeDB.txt");
	rename("temp.txt","EmployeeDB.txt");
}

