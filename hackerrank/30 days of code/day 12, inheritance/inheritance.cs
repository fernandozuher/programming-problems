// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

using static System.Console;


public static class Solution
{
    public static void Main()
    {
        var (personalData, studentData) = ReadInput();
        var student = new Student(personalData, studentData);
        student.PrintPerson();
        WriteLine("Grade: " + student.CalculateGrade());
    }

    private static (PersonalData, StudentData) ReadInput()
    {
        var line = ReadLine().Split();
        (string firstName, string lastName, int id) = (line[0], line[1], int.Parse(line[2]));
        ReadLine(); // Skip the next line
        int[] scores = [.. ReadLine().Split().Select(int.Parse)];
        return (new PersonalData(firstName, lastName, id), new StudentData(scores));
    }
}

public record PersonalData(string FirstName, string LastName, int Id);
public record StudentData(int[] Scores);

public class Person(PersonalData data)
{
    private string _firstName = data.FirstName, _lastName = data.LastName;
    private int _id = data.Id;

    public void PrintPerson()
    {
        WriteLine("Name: " + _lastName + ", " + _firstName + "\nID: " + _id);
    }
}

public class Student(PersonalData personalData, StudentData studentData) : Person(personalData)
{
    private int[] _scores = studentData.Scores;

    public char CalculateGrade()
    {
        int avg = _scores.Sum() / _scores.Length;

        if (avg > 100 || avg < 40)
            return 'T';
        else if (avg >= 90)
            return 'O';
        else if (avg >= 80)
            return 'E';
        else if (avg >= 70)
            return 'A';
        else if (avg >= 55)
            return 'P';
        return 'D';
    }
}
