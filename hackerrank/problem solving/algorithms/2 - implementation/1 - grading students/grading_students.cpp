// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// C++23

#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers();
vector<int> grade_students(const vector<int>& grades);
void print_numbers(const vector<int>& numbers);

int main()
{
    int n;
    cin >> n;
    vector grades{read_numbers()};
    vector rounded_grades{grade_students(grades)};
    print_numbers(rounded_grades);
    return 0;
}

vector<int> read_numbers()
{
    return {istream_iterator<int>(cin), istream_iterator<int>()};
}

vector<int> grade_students(const vector<int>& grades)
{
    constexpr int min_grade{38};
    return grades | views::transform([](int grade) {
               if (grade < min_grade)
                   return grade;
               int next_multiple_5{(grade / 5 + 1) * 5};
               return next_multiple_5 - grade < 3 ? next_multiple_5 : grade;
           })
           | ranges::to<vector>();
}

void print_numbers(const vector<int>& numbers)
{
    ranges::copy(numbers, ostream_iterator<int>(cout, "\n"));
}
