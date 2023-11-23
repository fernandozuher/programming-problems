// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);
vector<int> grading_students(const vector<int>& grades);
bool is_zero_remainder(const int grade);
void print_array(const vector<int>& array);

int main()
{
    int n;
    cin >> n;

    vector<int> array {read_int_array(n)};
    vector<int> result {grading_students(array)};
    print_array(result);

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        ranges::generate(array, []{int n; cin >> n; return n;});
        return array;
    }

    vector<int> grading_students(const vector<int>& grades)
    {
        vector<int> new_grades(grades.size());

        for (int i {}, min_grade {38}; i < grades.size(); ++i)

            if (grades.at(i) < min_grade || is_zero_remainder(grades.at(i)))
                new_grades.at(i) = grades.at(i);
            else {
                int quocient {grades.at(i) / 5};
                int next_multiple_5 {(quocient + 1) * 5};
                int difference {next_multiple_5 - grades.at(i)};
                new_grades.at(i) = difference < 3 ? next_multiple_5 : grades.at(i);
            }

        return new_grades;
    }

        bool is_zero_remainder(const int grade)
        {
            return grade % 5 == 0;
        }

    void print_array(const vector<int>& array)
    {
        for (const auto x : array)
            cout << x << '\n';
    }
