// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

int n = ReadNumbers(1)[0];
int[] grades = ReadNumbers(n);
Array.ForEach(GradingStudents(grades), Console.WriteLine);

int[] ReadNumbers(int n)
{
    return Enumerable.Range(0, n).Select(_ => int.Parse(Console.ReadLine()!)).ToArray();
}

// n: length of array grades
// T: O(n)
// S: O(1) extra space
int[] GradingStudents(int[] grades)
{
    for (int i = 0, minGrade = 38; i < grades.Length; i++)
    {
        if (grades[i] >= minGrade)
        {
            int nextMultiple5 = (grades[i] / 5 + 1) * 5;
            if (nextMultiple5 - grades[i] < 3)
                grades[i] = nextMultiple5;
        }
    }
    return grades;
}