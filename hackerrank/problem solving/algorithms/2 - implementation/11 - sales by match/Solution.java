// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// From Java 16

import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray(n);
        System.out.println(sockMerchant(array));
    }

        private static List<Integer> readIntArray(final int n) {
            return Stream.of(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }
    
        private static int sockMerchant(final List<Integer> socks) {
            int pairs = 0;
            var socksPairing = new HashMap<Integer, Boolean>();
    
            for (final int sock : socks) {
                if (socksPairing.get(sock) != null && socksPairing.get(sock)) {
                    ++pairs;
                    socksPairing.put(sock, !socksPairing.get(sock));
                } else
                    socksPairing.put(sock, true);
            }
    
            return pairs;
        }
}
