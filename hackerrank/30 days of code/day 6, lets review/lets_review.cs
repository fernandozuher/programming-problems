// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        for (int i = 0, n = int.Parse(Console.ReadLine()); i < n; ++i)
        {
            string word = Console.ReadLine();
            string word1 = "", word2 = "";
            bool isWord1Turn = true;

            foreach (char ch in word)
            {
                if (isWord1Turn)
                    word1 += ch;
                else
                    word2 += ch;
                isWord1Turn = !isWord1Turn;
            }

            Console.WriteLine($"{word1} {word2}");
        }
    }
}
