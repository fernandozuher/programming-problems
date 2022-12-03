using System;

class Result
{

    /*
     * Complete the 'gradingStudents' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts INTEGER_ARRAY grades as parameter.
     */

    private static bool isZeroRemainder(int grade)
    {
        return grade % 5 == 0;
    }

    public static List<int> gradingStudents(List<int> grades)
    {
        int n = grades.Count;
        List<int> newGrades = new List<int>(n);

        for (int i = 0, minGrade = 38; i < n; i++)
        {
            if (grades[i] < minGrade || isZeroRemainder(grades[i]))
                newGrades.Add(grades[i]);
            else
            {
                int quocient = grades[i] / 5;
                int nextMultiple5 = (quocient + 1) * 5;
                int difference = nextMultiple5 - grades[i];

                int result = difference < 3 ? nextMultiple5 : grades[i];
                newGrades.Add(result);
            }
        }
        return newGrades;
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int gradesCount = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> grades = new List<int>();

        for (int i = 0; i < gradesCount; i++)
        {
            int gradesItem = Convert.ToInt32(Console.ReadLine().Trim());
            grades.Add(gradesItem);
        }

        List<int> result = Result.gradingStudents(grades);

        textWriter.WriteLine(String.Join("\n", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
