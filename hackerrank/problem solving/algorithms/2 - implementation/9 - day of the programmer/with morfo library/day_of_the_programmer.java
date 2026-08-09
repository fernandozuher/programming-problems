// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

final int TRANSITION_YEAR = 1918;

void main() {
    int year = Reader.read(Integer::parseInt);
    IO.println(calcDateOf256thDay(year));
}

// T: O(1)
// S: O(1) extra space
String calcDateOf256thDay(int year) {
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
