// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// From Java 16

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import static java.util.stream.Collectors.toList;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int nRowsColumns = scan.nextInt();
        var matrix = Arrays.stream(new String[nRowsColumns]).map(_ -> scan.next()).collect(toList());
        changeMatrixToCavityMap(matrix);
        matrix.forEach(System.out::println);
    }

        public static void changeMatrixToCavityMap(List<String> matrix) {
            for (int i = 1, newSize = matrix.size() - 1; i < newSize; ++i)
                for (int j = 1; j < newSize; ++j)
                    if (isCellCavity(matrix, i, j))
                        matrix.set(i, generateStringWithCavity(matrix.get(i), j));
        }

            public static boolean isCellCavity(List<String> matrix, int i, int j) {
                return matrix.get(i - 1).charAt(j) < matrix.get(i).charAt(j)
                        && matrix.get(i).charAt(j - 1) < matrix.get(i).charAt(j)
                        && matrix.get(i + 1).charAt(j) < matrix.get(i).charAt(j)
                        && matrix.get(i).charAt(j + 1) < matrix.get(i).charAt(j);
            }

            public static String generateStringWithCavity(String line, int i) {
                final char cavity = 'X';
                char[] stringToChar = line.toCharArray();
                stringToChar[i] = cavity;
                return new String(stringToChar);
            }
}
