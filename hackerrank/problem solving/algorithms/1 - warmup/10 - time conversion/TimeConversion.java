// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

import java.util.Scanner;

public class TimeConversion {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        String time = scan.next();
        System.out.println(timeConversion(time));
    }

        public static String timeConversion(final String time) {
            String convertedTime = time.substring(0, 8);
            String hour = time.substring(0, 2);
            String dayPeriod = time.substring(8, 9);

            if (hour.equals("12")) {
                if (dayPeriod.equals("A")) {
                    String midnight = "00";
                    convertedTime = convertedTime.replace(hour, midnight);
                }
            } else if (dayPeriod.equals("P")) {
                int newHour = Integer.parseInt(hour);
                newHour += 12;
                convertedTime = convertedTime.replace(hour, String.valueOf(newHour));
            }

            return convertedTime;
        }
}
