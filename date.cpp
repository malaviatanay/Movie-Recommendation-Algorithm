#include <iostream>
using namespace std;
#include <string>
class Date {
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    int year;
    int month;
    int day;

    // RETURNS TRUE IF THE OBJECT'S DATE IS LESS THAN 'delete_before'
    bool compareDates(Date& delete_before) {
    if (year < delete_before.year ) 
        return true;
    else if (year  > delete_before.year )
        return false;
    else if (month < delete_before.month) 
        return true;
    else if (month > delete_before.month) 
        return false;
    else if (day < delete_before.day) 
        return true;
    else 
        return false;   
        }

    string printDate(){
        return (std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year));
    }
    };