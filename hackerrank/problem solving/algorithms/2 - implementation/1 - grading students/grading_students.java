import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'gradingStudents' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts INTEGER_ARRAY grades as parameter.
     */

    private static boolean isZeroRemainder(int grade) {
        return grade % 5 == 0;
    }

    public static List<Integer> gradingStudents(List<Integer> grades) {
        final int N = grades.size();
        List<Integer> newGrades = new ArrayList<Integer>(N);

        for (int i = 0, minGrade = 38; i < N; i++) {

            if (grades.get(i) < minGrade || isZeroRemainder(grades.get(i)))
                newGrades.add(grades.get(i));
            else {
                int quocient = grades.get(i) / 5;
                int nextMultiple5 = (quocient + 1) * 5;
                int difference = nextMultiple5 - grades.get(i);

                int result = difference < 3 ? nextMultiple5 : grades.get(i);
                newGrades.add(result);
            }
        }
        return newGrades;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int gradesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> grades = IntStream.range(0, gradesCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
        .map(String::trim)
        .map(Integer::parseInt)
        .collect(toList());

        List<Integer> result = Result.gradingStudents(grades);

        bufferedWriter.write(
            result.stream()
            .map(Object::toString)
            .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
