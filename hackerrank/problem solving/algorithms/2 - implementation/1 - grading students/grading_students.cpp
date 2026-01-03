// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
vector<int>& grading_students(vector<int>& grades);

int main()
{
    int n;
    cin >> n;
    vector grades{ read_numbers(n) };
    for (auto x : grading_students(grades))
        println("{}", x);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of grades
// T: O(n)
// S: O(1) extra space
vector<int>& grading_students(vector<int>& grades)
{
    for (constexpr int min_grade{ 38 }; auto& grade : grades) {
        if (grade >= min_grade) {
            int next_multiple_5{ (grade / 5 + 1) * 5 };
            if (next_multiple_5 - grade < 3)
                grade = next_multiple_5;
        }
    }
    return grades;
}