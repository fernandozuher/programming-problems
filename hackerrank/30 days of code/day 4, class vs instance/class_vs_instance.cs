// https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=true

using System;

class Person
{
    private int _age;

    public Person(int initialAge)
    {
        if (initialAge < 0)
        {
            _age = 0;
            Console.WriteLine("Age is not valid, setting age to 0.");
        }
        else
            _age = initialAge;
    }

    public void AmIOld()
    {
        if (_age < 13)
            Console.WriteLine("You are young.");
        else if (_age >= 13 && _age < 18)
            Console.WriteLine("You are a teenager.");
        else
            Console.WriteLine("You are old.");
    }

    public void YearPasses()
    {
        ++_age;
    }

    public static void Main()
    {
        for (int nTests = int.Parse(Console.ReadLine()); nTests-- > 0;)
        {
            int age = int.Parse(Console.ReadLine());
            Person p = new Person(age);
            p.AmIOld();

            for (int i = 3; i-- > 0; p.YearPasses());
            p.AmIOld();

            Console.WriteLine();
        }
    }
}
