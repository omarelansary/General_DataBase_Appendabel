#ifndef HOTELEMPLOYEEDATABASE_H_INCLUDED
#define HOTELEMPLOYEEDATABASE_H_INCLUDED

// Declare some constants
#define HOTELEMPLOYEE_NUM  50
#define HOTELSECTION_NUM   10

//////////////////////////////////////
typedef struct HotelEmployee HotelEmployee;
struct HotelEmployee{
    char fname[HOTELEMPLOYEE_NUM];
	char lname[HOTELEMPLOYEE_NUM];
	int roll;
	float salary;
	int sid[HOTELSECTION_NUM];
};

#endif HOTELEMPLOYEEDATABASE_H_INCLUDED
