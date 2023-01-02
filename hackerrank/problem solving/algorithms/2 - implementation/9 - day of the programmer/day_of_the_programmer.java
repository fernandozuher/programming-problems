// Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> year = readLineAsListInteger(bufferedReader);

        Result result = new Result(year.get(0));
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
        private int _year;
        private string _date;

        public Result(int year) {
            _year = year;
            _date = "";

            dayOfProgrammer();
            printResult();
        }

            private void dayOfProgrammer() {
                if (_year != 1918) {
                    bool isLeap = _year > 1918 ? isLeapGregorianYear() : isLeapJulianYear();
                    _date = isLeap ? "12.09." : "13.09.";
                }
                else
                    _date = "26.09.";
                
                _date += _year.toString();
            }
            

            private boolean _isLeapGregorianYear() {
                return _year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0);
            }
                
            private boolean isLeapJulianYear() {
                return _year % 4 == 0;
            }

            public void printResult() {
                System.out.println(_date);
            }
    }
