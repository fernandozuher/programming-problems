// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// C++23

#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers();
vector<int> grade_students(const vector<int>& grades);
bool is_zero_remainder(int grade);
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
    vector<int> rounded_grades(grades.size());

    for (constexpr int min_grade{38}; const auto &[grade, rounded_grade] : views::zip(grades, rounded_grades))

        if (grade < min_grade || is_zero_remainder(grade))
            rounded_grade = grade;
        else {
            int quotient{grade / 5};
            int next_multiple_5{(quotient + 1) * 5};
            int difference{next_multiple_5 - grade};
            rounded_grade = difference < 3 ? next_multiple_5 : grade;
        }

    return rounded_grades;
}

bool is_zero_remainder(int grade)
{
    return grade % 5 == 0;
}

void print_numbers(const vector<int>& numbers)
{
    ranges::copy(numbers, ostream_iterator<int>(cout, "\n"));
}
