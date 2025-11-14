// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <ranges>

using namespace std;

int beautifulDays(int startDay, int endDay, int divisor);
bool isDayBeautiful(int day, int divisor);
int reverseNumber(int number);

int main()
{
    int startDay, endDay, divisor;
    cin >> startDay >> endDay >> divisor;
    cout << beautifulDays(startDay, endDay, divisor) << '\n';
    return 0;
}

int beautifulDays(int startDay, int endDay, int divisor)
{
    return ranges::count_if(views::iota(startDay, endDay + 1),
                            [divisor](auto day) { return isDayBeautiful(day, divisor); });
}

bool isDayBeautiful(int day, int divisor)
{
    return abs(day - reverseNumber(day)) % divisor == 0;
}

int reverseNumber(int number)
{
    auto s{to_string(number)};
    ranges::reverse(s);
    return stoi(s);
}
