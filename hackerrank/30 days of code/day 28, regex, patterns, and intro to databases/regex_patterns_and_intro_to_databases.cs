// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<string> names = CollectGmailUsers(n);
        names.Sort();
        names.ForEach(Console.WriteLine);
    }

    private static List<string> CollectGmailUsers(int n)
    {
        var names = new List<string>();

        while (n-- > 0)
        {
            string[] line = Console.ReadLine().Split();
            string name = line[0];
            string email = line[1];
            if (email.EndsWith("@gmail.com"))
                names.Add(name);
        }

        return names;
    }
}
