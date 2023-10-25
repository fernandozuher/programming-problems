// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        List<String> names = findNamesWithGmailDomainsEmailsFromStdin(n);
        sortInPlaceAndPrintNames(names);
    }

        private static List<String> findNamesWithGmailDomainsEmailsFromStdin(int n) {
            List<String> names = new ArrayList<String>();

            IntStream.range(0, n).forEach(i -> {
                String name = scan.next();
                String emailId = scan.next();

                if (emailId.contains("@gmail.com"))
                    names.add(name);
            });

            return names;
        }

        private static void sortInPlaceAndPrintNames(List<String> names) {
            Collections.sort(names);
            for (String name : names)
                System.out.println(name);
        }
}
