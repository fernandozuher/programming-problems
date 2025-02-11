// https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=true

using static System.Console;

class Person
{
    private int _age;

    public Person(int initialAge)
    {
        if (initialAge < 0)
        {
            _age = 0;
            WriteLine("Age is not valid, setting age to 0.");
        }
        else
            _age = initialAge;
    }

    public void AmIOld()
    {
        if (_age < 13)
            WriteLine("You are young.");
        else if (_age >= 13 && _age < 18)
            WriteLine("You are a teenager.");
        else
            WriteLine("You are old.");
    }

    public void YearPasses()
    {
        ++_age;
    }

    public static void Main()
    {
        for (int nTests = int.Parse(ReadLine()); nTests-- > 0;)
        {
            int age = int.Parse(ReadLine());
            Person p = new Person(age);
            p.AmIOld();

            for (int i = 3; i-- > 0; p.YearPasses());
            p.AmIOld();

            WriteLine();
        }
    }
}
