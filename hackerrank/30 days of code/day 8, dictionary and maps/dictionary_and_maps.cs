// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(ReadLine());
        var phoneBook = InitPhoneBook(n);
        QueryNames(phoneBook);
    }

    private static Dictionary<string, string> InitPhoneBook(int n)
    {
        var phoneBook = new Dictionary<string, string>();
        while (n-- > 0)
        {
            string[] entry = ReadLine().Split(' ');
            phoneBook.Add(entry[0], entry[1]);
        }
        return phoneBook;
    }

    private static void QueryNames(Dictionary<string, string> phoneBook)
    {
        for (string name; (name = ReadLine()) != null;)
            if (phoneBook.TryGetValue(name, out string phone))
                WriteLine("{0}={1}", name, phone);
            else
                WriteLine("Not found");
    }
}
