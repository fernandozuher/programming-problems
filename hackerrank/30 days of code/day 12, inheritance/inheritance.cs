// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

using System;
using System.Linq;

class Solution
{
    public static void Main()
    {
        string[] inputs = Console.ReadLine().Split();

        string firstName = inputs[0];
        string lastName = inputs[1];
        int id = int.Parse(inputs[2]);

        int nScores = int.Parse(Console.ReadLine());
        int[] scores = Console.ReadLine().Split().Select(int.Parse).ToArray();

        Student student = new Student(firstName, lastName, id, scores);
        student.PrintPerson();
        Console.WriteLine("Grade: " + student.Calculate());
    }
}

    class Person
    {
        protected string firstName, lastName;
        protected int id;

        public Person(string firstName, string lastName, int id)
        {
            this.firstName = firstName;
            this.lastName = lastName;
            this.id = id;
        }

        public void PrintPerson()
        {
            Console.WriteLine("Name: " + lastName + ", " + firstName + "\nID: " + id);
        }
    }

        class Student: Person
        {
            private int[] _scores;

            public Student(string firstName, string lastName, int id, int[] scores)
            : base(firstName, lastName, id)
            {
                _scores =  scores;
            }

            public char Calculate()
            {
                int avg = (int)Queryable.Average(_scores.AsQueryable());

                if (avg >= 90 && avg <= 100)
                    return 'O';
                else if (avg >= 80 && avg < 90)
                    return 'E';
                else if (avg >= 70 && avg < 80)
                    return 'A';
                else if (avg >= 55 && avg < 70)
                    return 'P';
                else if (avg >= 40 && avg < 55)
                    return 'D';
                else
                    return 'T';
            }
        }
