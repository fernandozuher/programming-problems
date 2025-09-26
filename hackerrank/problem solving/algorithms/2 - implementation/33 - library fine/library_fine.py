# https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

from datetime import datetime

HACKOS_DAYS_FINE = 15
HACKOS_MONTHS_FINE = 500
HACKOS_YEARS_FINE = 10000


def main():
    return_date = read_date()
    due_date = read_date()
    print(calculate_fine(return_date, due_date))


def read_date():
    day, month, year = map(int, input().split())
    return datetime(year, month, day)


def calculate_fine(return_date, due_date):
    if returned_on_time(return_date, due_date):
        return 0
    if return_date.year > due_date.year:
        return HACKOS_YEARS_FINE
    if return_date.year == due_date.year and return_date.month > due_date.month:
        return (return_date.month - due_date.month) * HACKOS_MONTHS_FINE
    return (return_date.day - due_date.day) * HACKOS_DAYS_FINE


def returned_on_time(return_date, due_date):
    return (return_date.year < due_date.year) or \
        ((return_date.year == due_date.year) and (return_date.month < due_date.month)) or \
        ((return_date.year == due_date.year) and (return_date.month == due_date.month) and (
                return_date.day <= due_date.day))


if __name__ == '__main__':
    main()
