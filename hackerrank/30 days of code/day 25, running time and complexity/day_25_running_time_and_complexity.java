import java.util.*;

public class Solution {
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        
        for (var n = sc.nextInt(); n-- > 0; ) {
            var number = sc.nextInt();

            if (number == 1) {
                System.out.println("Not prime");
                continue;
            }

            int i = 2, limit = (int) Math.sqrt(number);
            for (; i <= limit; i++)
                if (number % i == 0) {
                    System.out.println("Not prime");
                    break;
                }

            if (i > limit)
                System.out.println("Prime");
        }
    }
}
