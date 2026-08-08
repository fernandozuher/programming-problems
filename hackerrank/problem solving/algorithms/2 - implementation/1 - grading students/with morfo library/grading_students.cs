// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
int[] grades = Reader.Read<int>(n);
Writer.Println(GradingStudents(grades));

// n: length of grades
// T: O(n)
// S: O(1) extra space
int[] GradingStudents(int[] grades)
{
    for (int i = 0, minGrade = 38; i < grades.Length; i++)
    {
        if (grades[i] < minGrade)
            continue;
        int nextMultiple5 = (grades[i] / 5 + 1) * 5;
        if (nextMultiple5 - grades[i] < 3)
            grades[i] = nextMultiple5;
    }
    return grades;
}
