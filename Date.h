#ifndef DATE_H
#define DATE_H
#include <string>
#include "Date.h"

class Date
{
public:
  int year;
  int month;
  int day;
  std::string error;
  Date()
  {
    year = 0;
    month = 0;
    day = 0;
  }
  std::string validate();
};

std::string Date::validate()
{
  if (day < 1 || day > 31)
  {
    return "this day is invalid.";
  }
  else if (month < 1 || month > 12)
  {
    return "this month is invalid.";
  }
  else if (year < 0)
  {
    return "this year is invalid.";
  }

  if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
  {
    return "day 31 does not exist for this month.";
  }
  else if ((month == 2) && (year % 4 == 0) && day > 29)
  {
    return "this day is invalid for Febuary.";
  }
  else if ((month == 2) && (year % 4 != 0) && day > 28)
  {
    return "this day is invalid for Febuary.";
  }

  return "None.";
}

#endif