// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int beautifulDays(int startDay, int endDay, int divisor);
bool isDayBeautiful(int day, int divisor);
int reverseNumber(int number);

int main()
{
    int startDay, endDay, divisor;
    cin >> startDay >> endDay >> divisor;
    cout << beautifulDays(startDay, endDay, divisor);
    return 0;
}

// n: range (end_day - start_day + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
int beautifulDays(int startDay, int endDay, int divisor)
{
    return ranges::count_if(views::iota(startDay, endDay + 1),
        [divisor](auto day) { return isDayBeautiful(day, divisor); });
}

bool isDayBeautiful(int day, int divisor)
{
    return (day - reverseNumber(day)) % divisor == 0;
}

int reverseNumber(int number)
{
    auto s{ to_string(number) };
    ranges::reverse(s);
    return stoi(s);
}
