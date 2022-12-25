// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

using System;

class Result
{
    /*
     * Complete the 'kangaroo' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. INTEGER x1
     *  2. INTEGER v1
     *  3. INTEGER x2
     *  4. INTEGER v2
     */

    public static string kangaroo(int x1, int v1, int x2, int v2)
    {
        if (v2 >= v1)
            return "NO";
        for (; x1 < x2; x1 += v1, x2 += v2);
        return x1 == x2 ? "YES" : "NO";
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);
        
        int[] numbers = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int x1 = numbers[0];
        int v1 = numbers[1];
        int x2 = numbers[2];
        int v2 = numbers[3];

        string result = Result.kangaroo(x1, v1, x2, v2);
        textWriter.WriteLine(result);
        textWriter.Flush();

        textWriter.Close();
    }
}
