// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int beautiful_days(int start_day, int end_day, int divisor);
bool is_beautiful_day(int day, int divisor);
int reverse_number(int number);

int main()
{
    int start_day, end_day, divisor;
    cin >> start_day >> end_day >> divisor;
    cout << beautiful_days(start_day, end_day, divisor);
    return 0;
}

// n: range (end_day - start_day + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
int beautiful_days(int start_day, int end_day, int divisor)
{
    return ranges::count_if(views::iota(start_day, end_day + 1),
        [divisor](auto day) { return is_beautiful_day(day, divisor); });
}

bool is_beautiful_day(int day, int divisor)
{
    return (day - reverse_number(day)) % divisor == 0;
}

int reverse_number(int number)
{
    auto s{ to_string(number) };
    ranges::reverse(s);
    return stoi(s);
}
