// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

int n = ReadNumbers(1)[0];
int[] grades = ReadNumbers(n);
int[] roundedGrades = GradeStudents(grades);
Array.ForEach(roundedGrades, Console.WriteLine);

int[] ReadNumbers(int n)
{
    return Enumerable.Range(0, n).Select(_ => int.Parse(Console.ReadLine()!)).ToArray();
}

int[] GradeStudents(int[] grades)
{
    const int minGrade = 38;
    return grades.Select(grade =>
    {
        if (grade < minGrade)
            return grade;
        int nextMultiple5 = (grade / 5 + 1) * 5;
        return nextMultiple5 - grade < 3 ? nextMultiple5 : grade;
    }).ToArray();
}
