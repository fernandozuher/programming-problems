# https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

from datetime import datetime


def main():
    returned_date = read_date()
    due_date = read_date()
    fine = 0 if returned_date <= due_date else FineOnDelay(returned_date, due_date).fine()
    print(fine)


def read_date():
    day, month, year = map(int, input().split())
    return datetime(year, month, day)


class FineOnDelay:
    FINE_PER_YEAR = 10000
    FINE_PER_MONTH = 500
    FINE_PER_DAY = 15

    def __init__(self, returned_date, due_date):
        self.__returned_date, self.__due_date = returned_date, due_date
        self.__fine = self.__calculate_fine()

    def __calculate_fine(self):
        fine = self.__late_by_year()
        if fine:
            return fine

        fine = self.__late_by_month()
        if fine:
            return fine

        return self.__late_by_day()

    def __late_by_year(self):
        if self.__returned_date.year > self.__due_date.year:
            return FineOnDelay.FINE_PER_YEAR
        return 0

    def __late_by_month(self):
        if self.__is_same_year() and self.__returned_date.month > self.__due_date.month:
            return (self.__returned_date.month - self.__due_date.month) * FineOnDelay.FINE_PER_MONTH
        return 0

    def __is_same_year(self):
        return self.__returned_date.year == self.__due_date.year

    def __late_by_day(self):
        if self.__is_same_year() and self.__is_same_month() and self.__returned_date.day > self.__due_date.day:
            return (self.__returned_date.day - self.__due_date.day) * FineOnDelay.FINE_PER_DAY
        return 0

    def __is_same_month(self):
        return self.__returned_date.month == self.__due_date.month

    def fine(self):
        return self.__fine


if __name__ == "__main__":
    main()
