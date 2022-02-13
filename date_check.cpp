#include "date_check.h"

bool IsLeapYear(int year)
{
    if(((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
        return true;
    return false;
}

bool IsLegal(int year,int mon,int day)
{
	if(year < 0 || mon <= 0 || mon > 12 || day <= 0 || day > 31)return false;
	if(1 == mon || 3 == mon || 5 == mon || 7 == mon || 8 == mon || 10 == mon || 12 == mon){
		return true;
	}
	if(IsLeapYear(year)){
		if(2 == mon && (30 == day || 31 == day))return false;
		return true;
	}
	else {
		if(2 == mon && (29 == day || 30 == day || 31 == day))return false;
		return true;

	}
}

