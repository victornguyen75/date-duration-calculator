#include <iostream>
#include "Date.h"
using namespace std;

int rataDie(int month, int day, int year);

int main()
{
  Date date1 = {0, 0, 0};
  Date date2 = {0, 0, 0};
  int difference = 0;

  cout << "Please enter two dates: ";
  scanf("%d/%d/%d %d/%d/%d", &date1.month, &date1.day, &date1.year, &date2.month, &date2.day, &date2.year);
  printf("\nDate 1: %d/%d/%d\nDate 2: %d/%d/%d\n", date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);

  date1.error = date1.validate();
  date2.error = date2.validate();

  if (date1.error != "None.")
  {
    cout << "\nDate 1 is invalid because " << date1.error << endl;
    return 0;
  }
  else if (date2.error != "None.")
  {
    cout << "\nDate 2 is invalid because " << date2.error << endl;
    return 0;
  }

  difference = rataDie(date2.month, date2.day, date2.year) - rataDie(date1.month, date1.day, date1.year);
  cout << "The difference between the two dates is " << difference << " day(s)." << endl;
  return 0;
}

int rataDie(int month, int day, int year)
{
  if (month < 3)
  {
    year--;
    month += 12;
  }

  return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}