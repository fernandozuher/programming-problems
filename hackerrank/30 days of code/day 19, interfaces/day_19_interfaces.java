import java.io.*;
import java.util.*;

interface AdvancedArithmetic {
    public int divisorSum(int n);
}

class Calculator implements AdvancedArithmetic {
    public int divisorSum(int n) {
        var sum = 0;
        for (var i = 1; i <= n / 2; i++)
            if (n % i == 0)
                sum += i;
        return sum + n;
    }
}

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Calculator calc = new Calculator();
        System.out.println("I implemented: AdvancedArithmetic\n" + calc.divisorSum(n));
    }
}
