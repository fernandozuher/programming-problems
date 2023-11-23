// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = _readIntArray(n);
        _printArray(_gradingStudents(array));
    }

        private static List<int> _readIntArray(int n)
        {
            List<int> array = new List<int>(n);
            for (int i = 0; i < n; ++i)
                array.Add(int.Parse(Console.ReadLine()));
            return array;
        }

        private static List<int> _gradingStudents(List<int> grades)
        {
            int n = grades.Count;
            List<int> newGrades = new List<int>(n);

            for (int i = 0, minGrade = 38; i < n; ++i)
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

            private static bool isZeroRemainder(int grade)
            {
                return grade % 5 == 0;
            }

        private static void _printArray(List<int> array)
        {
            foreach (var x in array)
                Console.WriteLine(x);
        }
}
