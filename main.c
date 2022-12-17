
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudentDatabase.h"
#include "StudentManagement.h"
#include "EmployeeDatabase.h"
#include "EmployeeManagement.h"
#include "HotelEmployeeDatabase.h"
#include "HotelEmployeeManagement.h"


// Variable to keep track of
// number of students
int i/*change this*/ = 0; //  Change this i into number of student in your progrm
int studentNumber=0;
int NUM_OF_FACTORY_EMP=0;
int NUM_OF_HOTEL_EMP=0;
void main()

{
    int menuChoice;
    printf("Choose the data base: 1.University, 2. Factory, 3.Hotelsss\n");
    scanf("%d",&menuChoice);
    switch(menuChoice)
    {

        case 1:
            int choice1, count1;
            while (i = 1) {
                printf("The Tasks that you "
                    "want to perform\n");
                printf("1. Add the Student Details\n");
                printf("2. Find the Student "
                    "Details by Roll Number\n");
                printf("3. Find the Student "
                    "Details by First Name\n");
                printf("4. Find the Student "
                    "Details by Course Id\n");
                printf("5. Find the Total number"
                    " of Students\n");
                printf("6. Delete the Students Details"
                    " by Roll Number\n");
                printf("7. Update the Students Details"
                    " by Roll Number\n");
                printf("8. To Exit\n");
                printf("Enter your choice to "
                    "find the task\n");
                scanf("%d", &choice1);
                switch (choice1) {
                case 1:
                    add_student();
                    break;
                case 2:
                    find_rl();
                    break;
                case 3:
                    find_fn();
                    break;
                case 4:
                    find_c();
                    break;
                case 5:
                    tot_s();
                    break;
                case 6:
                    del_s();
                    break;
                case 7:
                    up_s();
                    break;
                case 8:
                    exit(0);
                    break;
                }
            }
        case 2:
            int choice2, count2;
            while (i = 1) {
                printf("The Tasks that you "
                    "want to perform\n");
                printf("1. Add the Employee Details\n");
                printf("2. Find the Employee "
                    "Details by Roll Number\n");
                printf("3. Find the Employee "
                    "Details by First Name\n");
                printf("4. Find the Employee "
                    "Details by Factory Section Id\n");
                printf("5. Find the Total number"
                    " of Employees\n");
                printf("6. Delete the Employees Details"
                    " by Roll Number\n");
                printf("7. Update the Employees Details"
                    " by Roll Number\n");
                printf("8. To Exit\n");
                printf("Enter your choice to "
                    "find the task\n");
                scanf("%d", &choice2);
                switch (choice2) {
                case 1:
                    add_Factory_emp();
                    break;
                case 2:
                    find_rl_Factory_emp();
                    break;
                case 3:
                    find_fn_Factory_emp();
                    break;
                case 4:
                    find_Factory_s();
                    break;
                case 5:
                    tot_Factory_emp();
                    break;
                case 6:
                    del_Factory_emp();
                    break;
                case 7:
                    up_Factory_emp();
                    break;
                case 8:
                    exit(0);
                    break;
                }
            }
        case 3:
            int choice3, count3;
            while (i = 1) {
                printf("The Tasks that you "
                    "want to perform\n");
                printf("1. Add the Hotel Employee Details\n");
                printf("2. Find the Hotel Employee "
                    "Details by Roll Number\n");
                printf("3. Find the Employee "
                    "Details by First Name\n");
                printf("4. Find the Employee "
                    "Details by Hotel Section Id\n");
                printf("5. Find the Total number"
                    " of Hotel Employees\n");
                printf("6. Delete the Hotel Employees Details"
                    " by Roll Number\n");
                printf("7. Update the Hotel Employees Details"
                    " by Roll Number\n");
                printf("8. To Exit\n");
                printf("Enter your choice to "
                    "find the task\n");
                scanf("%d", &choice3);
                switch (choice3) {
                case 1:
                    add_Hotelemployee();
                    break;
                case 2:
                    find_rl_Hotel_emp();
                    break;
                case 3:
                    find_fn_Hotel_emp();
                    break;
                case 4:
                    find_Hotel_s();
                    break;
                case 5:
                    tot_Hotel_e();
                    break;
                case 6:
                    del_Hotel_e();
                    break;
                case 7:
                    up_Hotel_e();
                    break;
                case 8:
                    exit(0);
                    break;
                }
            }

    }
}
