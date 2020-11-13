#include <iostream>
using namespace std;

struct date
{
  int year;
  int month;
  int day;

  // Date validation: years, months, days (take into account leap year)
  //   a. No alphabets or special characters; only positive integers
  //   b. Month validation: between 1-13
  //   c. Day validation: between 1-31 (depending on month and leap year)
};

int rataDie(int month, int day, int year);

int main()
{
  date date1 = {0, 0, 0};
  date date2 = {0, 0, 0};
  int difference = 0;

  cout << "Please enter two dates: ";

  scanf("%d/%d/%d %d/%d/%d", &date1.month, &date1.day, &date1.year, &date2.month, &date2.day, &date2.year);

  printf("\nDate 1: %d/%d/%d\nDate 2: %d/%d/%d\n", date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);

  difference = rataDie(date2.month, date2.day, date2.year) - rataDie(date1.month, date1.day, date1.year);

  cout << "The difference between the two dates is " << difference << " days." << endl;
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