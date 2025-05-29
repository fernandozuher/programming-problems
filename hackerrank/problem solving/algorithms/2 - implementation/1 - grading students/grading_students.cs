// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> grades = ReadNumbers(n);
        List<int> roundedGrades = GradeStudents(grades);
        roundedGrades.ForEach(Console.WriteLine);
    }

    private static List<int> ReadNumbers(int n)
    {
        return Enumerable.Range(0, n).Select(_ => int.Parse(Console.ReadLine())).ToList();
    }

    private static List<int> GradeStudents(List<int> grades)
    {
        const int minGrade = 38;
        return grades.Select(grade =>
        {
            if (grade < minGrade)
                return grade;
            int nextMultiple5 = (grade / 5 + 1) * 5;
            return nextMultiple5 - grade < 3 ? nextMultiple5 : grade;
        }).ToList();
    }
}
