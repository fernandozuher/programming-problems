using System;

class Solution {
    static void Main(String[] args) {        
        for (var n = Int32.Parse(Console.ReadLine()); n-- > 0; ) {
            var number = Int32.Parse(Console.ReadLine());

            if (number == 1) {
                Console.WriteLine("Not prime");
                continue;
            }

            int i = 2, limit = (int)Math.Sqrt(number);
            for (; i <= limit; i++)
                if (number % i == 0) {
                    Console.WriteLine("Not prime");
                    break;
                }

            if (i > limit)
                Console.WriteLine("Prime");
        }
    }
}
