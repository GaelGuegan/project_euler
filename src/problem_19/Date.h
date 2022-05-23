/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date
{
 public:
  int day;
  int month;
  int year;
  string day_name;

  Date(int day, int month, int year, string day_name);
};

#endif
