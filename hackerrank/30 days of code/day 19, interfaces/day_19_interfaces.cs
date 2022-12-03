using System;
public interface AdvancedArithmetic {
    int divisorSum(int n);
}

public class Calculator : AdvancedArithmetic
{
    public int divisorSum(int n) {
        var sum = 0;
        for (var i = 1; i <= n / 2; i++)
            if (n % i == 0)
                sum += i;
        return sum + n;
    }
}

// Imutable HackerRank code below
class Solution
{
    static void Main(string[] args) {
        int n = Int32.Parse(Console.ReadLine());
        AdvancedArithmetic myCalculator = new Calculator();
        int sum = myCalculator.divisorSum(n);
        Console.WriteLine("I implemented: AdvancedArithmetic\n" + sum);
    }
}
