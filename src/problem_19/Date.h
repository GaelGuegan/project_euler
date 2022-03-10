#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date {
     public:
         int day;
         int month;
         int year;
         string day_name;

         Date(int day, int month, int year, string day_name);
};

#endif
