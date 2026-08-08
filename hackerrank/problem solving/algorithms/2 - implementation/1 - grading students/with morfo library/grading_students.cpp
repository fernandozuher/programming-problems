// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

vector<int>& grading_students(vector<int>& grades);

int main()
{
	int n = morfo::read();
	vector<int> grades = morfo::read(n);
	morfo::println(grading_students(grades));
	return 0;
}

// n: length of grades
// T: O(n)
// S: O(1) extra space
vector<int>& grading_students(vector<int>& grades)
{
	for (constexpr int min_grade{ 38 }; auto& grade : grades)
		if (grade >= min_grade)
			if (int next_multiple_5{ (grade / 5 + 1) * 5 }; next_multiple_5 - grade < 3)
				grade = next_multiple_5;
	return grades;
}
