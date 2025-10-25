# https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

TRANSITION_YEAR = 1918


def main():
    year = int(input())
    print(calculate_date_of_256th_day(year))


def calculate_date_of_256th_day(year):
    if year == TRANSITION_YEAR:
        day = '26'
    else:
        day = '12' if is_leap_year(year) else '13'
    return day + '.09.' + str(year)


def is_leap_year(year):
    if year < TRANSITION_YEAR:
        return is_leap_julian_year(year)
    if year > TRANSITION_YEAR:
        return is_leap_gregorian_year(year)
    return False


def is_leap_julian_year(year):
    return not (year % 4)


def is_leap_gregorian_year(year):
    return (not (year % 400)) or (not (year % 4) and year % 100)


if __name__ == '__main__':
    main()
