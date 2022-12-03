import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String timeConversion(String time) {
        String convertedTime = time.substring(0, 8);
        String hourString = time.substring(0, 2);
        String periodOfDay = time.substring(8, 9);

        if (hourString.equals("12")) {
            if (periodOfDay.equals("A"))
                convertedTime = convertedTime.replace(hourString, "00");
        }
        else if (periodOfDay.equals("P")) {
            int hour = Integer.parseInt(hourString);
            hour += 12;
            convertedTime = convertedTime.replace(hourString, String.valueOf(hour));
        }
        return convertedTime;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.timeConversion(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
