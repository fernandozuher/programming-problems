// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read(int n);
vector<int> grading_students(const vector<int>& grades);
bool is_zero_remainder(int grade);

int main()
{
    int n;
    cin >> n;
    ranges::copy(grading_students(read(n)), ostream_iterator<int>(cout, "\n"));
    return 0;
}

    template<class T>
    vector<T> read(const int n)
    {
        vector<T> array(n);
        copy_n(istream_iterator<T>(cin), n, array.begin());
        return array;
    }

    vector<int> grading_students(const vector<int>& grades)
    {
        vector<int> new_grades(grades.size());

        for (constexpr int min_grade{38}; const auto& [grade, new_grade] : views::zip(grades, new_grades))

            if (grade < min_grade || is_zero_remainder(grade))
                new_grade = grade;
            else {
                int quotient{grade / 5};
                int next_multiple_5{(quotient + 1) * 5};
                int difference{next_multiple_5 - grade};
                new_grade = difference < 3 ? next_multiple_5 : grade;
            }

        return new_grades;
    }

        bool is_zero_remainder(const int grade)
        {
            return grade % 5 == 0;
        }
