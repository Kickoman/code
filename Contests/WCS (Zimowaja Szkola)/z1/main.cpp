#include <iostream>
#include <cstdio>

using namespace std;

string rome(int x)
{
  int arab[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
  string roman[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
  string res;
  int i = 12;
  while (x > 0)
  {
    if (x >= arab[i])
    {
      res += roman[i];
      x -= arab[i];
    }
    else
      --i;
  }
  return res;
}

int main()
{
#ifdef LOCAL
  freopen("../task.in", "r", stdin);
  freopen("../task.out", "w", stdout);
  #define debug(...) printf(__VA_ARGS__);
#else
  #define debug(...)
  #define cerr if(0)cerr
#endif // LOCAL
  int n;
  cin >> n;
  cerr << rome(15);
  int year = 1, month = 1, day = 1;
  int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int i = 0; i < n - 1; ++i)
  {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
      days[2] = 29;
    else
      days[2] = 28;
    day++;
    if (day > days[month])
      month++,
      day = 1;
    if (month > 12)
      month = 1,
      year++;
  }
  cout << rome(day) << "." << rome(month) << "." << rome(year);
  return 0;
}
