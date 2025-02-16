// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

using System.Text;
using static System.Console;

public class Solution
{
    public static void Main()
    {
        for (int i = 0, n = int.Parse(ReadLine()); i < n; i++)
        {
            string word = ReadLine();
            StringBuilder word1 = new StringBuilder(), word2 = new StringBuilder();
            bool isWord1Turn = true;

            foreach (char ch in word)
            {
                if (isWord1Turn)
                    word1.Append(ch);
                else
                    word2.Append(ch);
                isWord1Turn = !isWord1Turn;
            }

            WriteLine($"{word1} {word2}");
        }
    }
}
