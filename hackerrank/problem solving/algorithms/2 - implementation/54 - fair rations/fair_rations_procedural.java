// Source: https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;

public class FairRations {
    private static Scanner _scanner = new Scanner(System.in);

    public static void main(String[] args) {
        final int nSubjects = _scanner.nextInt();
        List<Integer> nLoavesOfEachPerson = Arrays.asList(new Integer[nSubjects]).stream().map(element -> _scanner.nextInt()).collect(Collectors.toList());
        System.out.println(_findMinLoavesToSatisfyRules(nLoavesOfEachPerson));
    }

        private static String _findMinLoavesToSatisfyRules(List<Integer> nLoavesOfEachPerson) {
            int minLoavesToSatisfyRules = 0;

            for (int i = 0, size = nLoavesOfEachPerson.size() - 1; i < size; i++)
                if (nLoavesOfEachPerson.get(i) % 2 == 1) {
                    nLoavesOfEachPerson.set(i, nLoavesOfEachPerson.get(i) + 1);
                    nLoavesOfEachPerson.set(i + 1, nLoavesOfEachPerson.get(i + 1) + 1);
                    minLoavesToSatisfyRules += 2;
                }

            return nLoavesOfEachPerson.get(nLoavesOfEachPerson.size() - 1) % 2 == 1 ? "NO" : Integer.toString(minLoavesToSatisfyRules);
        }
}
