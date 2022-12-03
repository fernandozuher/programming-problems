using System;

class Solution
{
    public static void Main(string[] args)
    {
        string S = Console.ReadLine();

        try {
            Console.WriteLine(int.Parse(S));
        }
        catch (FormatException e) {
            Console.WriteLine("Bad String");
        }
    }
}
