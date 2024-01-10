// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

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

        List<Integer> array = readIntArray();
        var obj = new SalesByMatch(array);
        System.out.println(obj.pairs());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class SalesByMatch {
        private List<Integer> socks;
        private int nPairs;

        public SalesByMatch(final List<Integer> socks) {
            this.socks = socks;
            nPairs = 0;
            sockMerchant();
        }

            private void sockMerchant() {
                var socksPairing = new HashMap<Integer, Boolean>();

                for (final int sock : socks) {
                    if (socksPairing.get(sock) != null && socksPairing.get(sock))
                        ++nPairs;

                    boolean value = socksPairing.get(sock) != null ? !socksPairing.get(sock) : true;
                    socksPairing.put(sock, value);
                }
            }

        public int pairs() {
            return nPairs;
        }
    }
