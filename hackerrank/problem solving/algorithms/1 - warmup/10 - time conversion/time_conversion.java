// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true
// Java 25

void main() {
    String time = IO.readln();
    IO.print(to24HourTime(time));
}

// T: O(1)
// S: O(1) extra space
String to24HourTime(String hour12) {
    String hour24 = hour12.substring(0, 8);
    String hour = hour12.substring(0, 2);
    String dayPeriod = hour12.substring(8, 9);

    if ((hour.equals("12") && dayPeriod.equals("A")) || (!hour.equals("12") && dayPeriod.equals("P"))) {
        String newHour = genNewHour(dayPeriod, hour);
        hour24 = hour24.replace(hour, newHour);
    }

    return hour24;
}

String genNewHour(String dayPeriod, String hour) {
    if (dayPeriod.equals("A")) return "00";
    int newHour = Integer.parseInt(hour);
    newHour += 12;
    return String.valueOf(newHour);
}
