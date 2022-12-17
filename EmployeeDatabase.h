#ifndef EMPLOYEEDATABASE_H_INCLUDED
#define EMPLOYEEDATABASE_H_INCLUDED

// Declare some constants
#define EMPLOYEE_NUM  50
#define SECTION_NUM   10

//////////////////////////////////////
typedef struct Employee Employee;
struct Employee{
    char fname[EMPLOYEE_NUM];
	char lname[EMPLOYEE_NUM];
	int roll;
	float salary;
	int sid[SECTION_NUM];
};

#endif EMPLOYEEDATABASE_H_INCLUDED
