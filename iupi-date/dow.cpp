#include <iostream>

// see https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Sakamoto's_methods
// The result of the formula will be a number between 0 and 6, where: 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday.
int dayofweek(int y, int m, int d)
/* 1 <= m <= 12, y > 1752 (in the U.K.), or 1582 (in Spain) */
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if ( m < 3 )
    {
        y -= 1;
    }
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

int main() {

  std::cout << dayofweek(2026, 8, 25) << std::endl;
  return 0;
}
