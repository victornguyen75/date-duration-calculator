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
  Date()
  {
    year = 0;
    month = 0;
    day = 0;
  }
  void validate();
  std::string getError();

private:
  std::string error;
};

void Date::validate()
{
  if (day < 1 || day > 31)
  {
    error = "this day is invalid.";
    return;
  }
  else if (month < 1 || month > 12)
  {
    error = "this month is invalid.";
    return;
  }
  else if (year < 0)
  {
    error = "this year is invalid.";
    return;
  }

  if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
  {
    error = "day 31 does not exist for this month.";
    return;
  }
  else if ((month == 2) && (year % 4 == 0) && day > 29)
  {
    error = "this day is invalid for Febuary.";
    return;
  }
  else if ((month == 2) && (year % 4 != 0) && day > 28)
  {
    error = "this day is invalid for Febuary.";
    return;
  }

  error = "None.";
}

std::string Date::getError()
{
  return error;
}
#endif