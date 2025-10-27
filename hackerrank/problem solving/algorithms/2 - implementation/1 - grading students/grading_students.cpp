// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// C++23

#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
vector<int> grade_students(const vector<int>& grades);

int main()
{
    int n;
    cin >> n;
    vector grades{read_numbers(n)};
    vector rounded_grades{grade_students(grades)};
    for (auto x : rounded_grades)
        cout << x << '\n';

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

vector<int> grade_students(const vector<int> &grades)
{
    constexpr int min_grade{38};
    return grades
           | views::transform([](int grade) {
               if (grade < min_grade)
                   return grade;
               int next_multiple_5{(grade / 5 + 1) * 5};
               return next_multiple_5 - grade < 3 ? next_multiple_5 : grade;
           })
           | ranges::to<vector>();
}
