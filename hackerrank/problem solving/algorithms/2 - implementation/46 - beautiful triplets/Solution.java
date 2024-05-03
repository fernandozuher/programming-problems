// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        int beautifulDifference = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray(n);
        System.out.println(findBeautifulTriplets(array, beautifulDifference));
    }

        public static List<Integer> readIntArray(final int n) {
            return Arrays.stream(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static int findBeautifulTriplets(final List<Integer> array, final int beautifulDifference) {
            int nBeautifulTriplets = 0;

            if (array.size() > 2)
                for (int i = 0; i < array.size() - 2; ++i) {
                    for (int j = i + 1; j < array.size() - 1; ++j) {
                        int firstDifference = array.get(j) - array.get(i);
        
                        if (firstDifference < beautifulDifference)
                            continue;
                        else if (firstDifference > beautifulDifference)
                            break;
        
                        for (int k = j + 1; k < array.size(); ++k) {
                            int secondDifference = array.get(k) - array.get(j);
                            if (secondDifference == beautifulDifference)
                                ++nBeautifulTriplets;
                            else if (secondDifference > beautifulDifference)
                                break;
                        }
                    }
                }

            return nBeautifulTriplets;
        }
}