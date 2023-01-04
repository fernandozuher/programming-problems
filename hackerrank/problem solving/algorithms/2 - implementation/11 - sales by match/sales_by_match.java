// Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        readLineAsListInteger(bufferedReader);
        List<Integer> socks = readLineAsListInteger(bufferedReader);

        Result result = new Result(socks);
    }

        private static List<Integer> readLineAsListInteger(BufferedReader bufferedReader)  {
            try {
                var numbers = Stream.of(bufferedReader.readLine().split(" "))
                              .map(Integer::parseInt)
                              .collect(toList());

                return numbers;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return null;
        }
}

    class Result {
        private List<Integer> _socks;
        private int _pairs;

        public Result(List<Integer> socks) {
            _socks = new ArrayList<Integer>(socks);
            _pairs = 0;

            _sockMerchant();
            printResult();
        }

            private void _sockMerchant() {
                var socksPairing = new HashMap<Integer, Boolean>();

                for (int sock : _socks) {
                    if (socksPairing.get(sock) != null && socksPairing.get(sock))
                        _pairs++;
                    
                    boolean value = socksPairing.get(sock) != null ? !socksPairing.get(sock) : true;
                    socksPairing.put(sock, value);
                }
            }

            public void printResult() {
                System.out.println(_pairs);
            }
    }
