// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class DiagonalDifference {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine(); // To take \n

        ArrayList<List<Integer>> matrix = readMatrix(n);
        System.out.println(diagonalDifference(matrix));
    }

        private static ArrayList<List<Integer>> readMatrix(final int n) {
            var matrix = new ArrayList<List<Integer>>();
            for (int i = 0; i < n; ++i) {
                List<Integer> list = Stream.of(scan.nextLine().split(" ")).map(Integer::parseInt).collect(toList());
                matrix.add(list);
            }
            return matrix;
        }

        private static int diagonalDifference(final ArrayList<List<Integer>> matrix) {
            int primaryDiagonal = 0, secondaryDiagonal = 0;

            for (int i = 0, j = matrix.size() - 1, n = matrix.size(); i < n; i++, j--) {
                primaryDiagonal += matrix.get(j).get(j);
                secondaryDiagonal += matrix.get(j).get(i);
            }
            return Math.abs(primaryDiagonal - secondaryDiagonal);
        }
}
