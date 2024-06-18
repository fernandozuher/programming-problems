// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int n = int.Parse(ReadLine());
        List<int> array = ReadIntArray(n);
        GradingStudents(array).ForEach(WriteLine);
    }

        static List<int> ReadIntArray(int n)
        {
            var array = new List<int>(new int[n]);
            for (int i = 0; i < n; ++i)
                array[i] = int.Parse(ReadLine());
            return array;
        }

        static List<int> GradingStudents(List<int> grades)
        {
            int n = grades.Count;
            var newGrades = new List<int>(new int[n]);

            for (int i = 0, minGrade = 38; i < n; ++i)
            {
                if (grades[i] < minGrade || IsZeroRemainder(grades[i]))
                    newGrades[i] = grades[i];
                else
                {
                    int quotient = grades[i] / 5;
                    int nextMultiple5 = (quotient + 1) * 5;
                    int difference = nextMultiple5 - grades[i];
                    newGrades[i] = difference < 3 ? nextMultiple5 : grades[i];
                }
            }

            return newGrades;
        }

            static bool IsZeroRemainder(int grade)
            {
                return grade % 5 == 0;
            }
}
