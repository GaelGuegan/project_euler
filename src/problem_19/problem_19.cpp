/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_19.h"
#include "Date.h"
#include "utils.h"
#include <string.h>
#include <list>

int check_month31(Date date)
{
    if (date.day == 32 && (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 ||
        date.month == 8 || date.month == 10 || date.month == 12)) {
        return 1;
    }

    return 0;
}

int check_month30(Date date)
{
    if (date.day == 31 && (date.month == 4 || date.month == 6 || date.month == 9 ||
        date.month == 11)) {
        return 1;
    }

    return 0;
}

int check_february(Date date)
{
    if (date.month == 2) {
        if (date.day == 29 && (date.year % 4 != 0 || date.year % 100 == 0)) {
            if (date.year % 400 == 0) {
                return 0;
            }
            return 1;
        }

        if (date.day == 30 && date.year % 4 == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char* argv[])
{
    list<Date> dates;
    string day_names[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    int day_num = 0;
    Date current_date = Date(1, 1, 1900, "monday");
    int count = 0;

    if (parse_opts(argc, argv) != 0)
        exit(1);

    // Create list of all days
    while (current_date.year < 2001) {
        dates.push_back(current_date);
        day_num++;
        current_date.day_name = day_names[day_num%7];
        current_date.day++;
        if (check_month31(current_date) || check_month30(current_date) || check_february(current_date)) {
            current_date.day = 1;
            current_date.month++;
        }
        if (current_date.month == 13) {
            current_date.year++;
            current_date.month=1;
        }
    }

    // Compute total of days    
    for (list<Date>::iterator it = dates.begin(); it != dates.end(); ++it) {
        if (it->year > 1900 && it->day == 1 && it->day_name == opt.day) {
            //cout << "Result: " << it->day << "/" << it->month << "/" << it->year << " : " << it->day_name << endl;
            count++;
        }
    }

    cout << "Total of " << opt.day << " : " << count << endl;

    return 0;
}
