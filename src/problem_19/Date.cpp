/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "Date.h"

Date::Date(int day, int month, int year, string day_name)
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->day_name = day_name;
}


