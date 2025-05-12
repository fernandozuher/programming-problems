// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

import java.util.*;

class Solution {
    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            List<String> names = collectGmailUsers(n, scan);
            Collections.sort(names);
            names.forEach(System.out::println);
        }
    }

    private static List<String> collectGmailUsers(int n, Scanner scan) {
        List<String> names = new ArrayList<>();

        while (n-- > 0) {
            String name = scan.next();
            String email = scan.next();
            if (email.endsWith("@gmail.com"))
                names.add(name);
        }

        return names;
    }
}