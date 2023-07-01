// Source: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;

public class CavityMap {
    private static Scanner _scanner = new Scanner(System.in);

    public static void main(String[] args) {
        final int nRowsColumns = _scanner.nextInt();

        List<String> matrix = Arrays.asList(new String[nRowsColumns]).stream().map(element -> _scanner.next()).collect(Collectors.toList());

        _changeMatrixToCavityMap(matrix);
        matrix.forEach(System.out::println);
    }

        private static void _changeMatrixToCavityMap(List<String> matrix) {
            for (int i = 1, newSize = matrix.size() - 1; i < newSize; i++)
                for (int j = 1; j < newSize; j++)
                    if (_isCellCavity(matrix, i, j)) {
                        final String stringWithCavity = _generateStringWithCavity(matrix.get(i), j);
                        matrix.set(i, stringWithCavity);
                    }
        }

            private static boolean _isCellCavity(List<String> matrix, int i, int j) {
                return matrix.get(i - 1).charAt(j) < matrix.get(i).charAt(j)
                       && matrix.get(i).charAt(j - 1) < matrix.get(i).charAt(j)
                       && matrix.get(i + 1).charAt(j) < matrix.get(i).charAt(j)
                       && matrix.get(i).charAt(j + 1) < matrix.get(i).charAt(j);
            }

            private static String _generateStringWithCavity(String line, int indexToPutCavity) {
                final char cavity = 'X';
                char[] stringToChar = line.toCharArray();
                stringToChar[indexToPutCavity] = cavity;
                return new String(stringToChar);
            }
}
