// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_int_array(int n);
vector<int> grading_students(const vector<int>& grades);
    bool is_zero_remainder(int grade);
void print_array(const vector<int>& array);

int main()
{
    int n;
    cin >> n;
    vector array {read_int_array(n)};
    vector result {grading_students(array)};
    print_array(result);

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        copy_n(istream_iterator<int>(cin), n, array.begin());
        return array;
    }

    vector<int> grading_students(const vector<int>& grades)
    {
        vector<int> new_grades(grades.size());

        for (constexpr int min_grade{38}; const auto& [grade, new_grade] : views::zip(grades, new_grades))

            if (grade < min_grade || is_zero_remainder(grade))
                new_grade = grade;
            else {
                int quotient {grade / 5};
                int next_multiple_5 {(quotient + 1) * 5};
                int difference {next_multiple_5 - grade};
                new_grade = difference < 3 ? next_multiple_5 : grade;
            }

        return new_grades;
    }

        bool is_zero_remainder(const int grade)
        {
            return grade % 5 == 0;
        }

    void print_array(const vector<int>& array)
    {
        ranges::copy(array, ostream_iterator<int>(cout, "\n"));
    }
