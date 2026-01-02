// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true
// Java 25

final int TRANSITION_YEAR = 1918;

void main() {
    int year = Integer.parseInt(IO.readln());
    IO.println(calculateDateOf256thDay(year));
}

String calculateDateOf256thDay(int year) {
    int day;
    if (year == TRANSITION_YEAR) day = 26;
    else day = isLeapYear(year) ? 12 : 13;
    return day + ".09." + year;
}

boolean isLeapYear(int year) {
    if (year < TRANSITION_YEAR) return isLeapJulianYear(year);
    if (year > TRANSITION_YEAR) return isLeapGregorianYear(year);
    return false;
}

boolean isLeapJulianYear(int year) {
    return year % 4 == 0;
}

boolean isLeapGregorianYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
