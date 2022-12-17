#ifndef STUDENTDATABASE_H_INCLUDED
#define STUDENTDATABASE_H_INCLUDED

// Declare some constants
#define STUDNET_NUM  50
#define COURSE_NUM   10

//////////////////////////////////////
typedef struct Student student;
struct Student{
    char fname[STUDNET_NUM];
	char lname[STUDNET_NUM];
	int roll;
	float cgpa;
	int cid[COURSE_NUM];
};

#endif  STUDENTDATABASE_H_INCLUDED
