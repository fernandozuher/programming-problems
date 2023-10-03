// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main() {
        int n = int.Parse(Console.ReadLine());
        AdvancedArithmetic calc = new Calculator();
        Console.WriteLine("I implemented: AdvancedArithmetic\n" + calc.DivisorSum(n));
    }
}

    public interface AdvancedArithmetic
    {
        int DivisorSum(int n);
    }

        public class Calculator: AdvancedArithmetic
        {
            public int DivisorSum(int n) {
                int sum = 0;
                for (int i = 1; i <= n / 2; ++i)
                    if (n % i == 0)
                        sum += i;
                return sum + n;
            }
        }
