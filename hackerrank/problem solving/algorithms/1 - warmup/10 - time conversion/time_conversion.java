// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true
// Java 25

void main() {
    String time = IO.readln();
    IO.print(timeConversion(time));
}

// T: O(1)
// S: O(1) extra space
String timeConversion(String time) {
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
