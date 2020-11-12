#include <iostream>
#include <string>

using namespace std;

int main()
{
  string date1 = "";
  string date2 = "";

  cout << "Please enter two dates: ";

  cin >> date1 >> date2;

  cout << "Date 1: " << date1 << endl
       << "Date 2: " << date2 << endl;

  return 0;
}