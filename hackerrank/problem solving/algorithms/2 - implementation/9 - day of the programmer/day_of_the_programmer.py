# https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

def main():
    year = int(input())
    obj = DayOfTheProgrammer(year)
    obj.calculate_date_of_256th_day()
    print(obj.date())


class DayOfTheProgrammer:
    _TRANSITION_YEAR = 1918

    def __init__(self, year):
        self._year = year
        self._date = ''

    def calculate_date_of_256th_day(self):
        if self._year != self._TRANSITION_YEAR:
            self._date = "12.09." if self._is_leap_year() else "13.09."
        else:
            self._date = "26.09."
        self._date += str(self._year)

    def _is_leap_year(self):
        return self._is_leap_gregorian_year() if self._year > self._TRANSITION_YEAR else self._is_leap_julian_year()

    def _is_leap_gregorian_year(self):
        return (not (self._year % 400)) or (not (self._year % 4) and self._year % 100)

    def _is_leap_julian_year(self):
        return not (self._year % 4)

    def date(self):
        return self._date


if __name__ == '__main__':
    main()
