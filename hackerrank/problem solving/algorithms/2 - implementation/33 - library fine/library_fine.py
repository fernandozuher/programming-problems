# https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

from enum import Enum
from datetime import datetime

def main():

    return_date = read_a_date()
    due_date = read_a_date()
    obj = LibrayFine(return_date, due_date)
    print(obj.fine())


def read_a_date():

    day, month, year = map(int, input().split())
    return datetime(year, month, day)


class LibrayFine:
    
    def __init__(self, return_date, due_date):

        self._return_date = return_date
        self._due_date = due_date
        self._fine = 0
        self._calculate_fine()


    def _calculate_fine(self):

        if self._were_books_returned_in_time():
            self._fine = 0
        elif self._is_return_date_late_in_more_than_or_equal_to_one_year():
            self._fine = HackosFine.hackos_years_fine.value
        elif self._is_return_date_late_in_more_than_or_equal_to_one_month():
            self._fine = (self._return_date.month - self._due_date.month) * HackosFine.hackos_months_fine.value
        else:
            self._fine = (self._return_date.day - self._due_date.day) * HackosFine.hackos_days_fine.value


    def _were_books_returned_in_time(self):

        if (self._return_date.year < self._due_date.year) or \
            ((self._return_date.year == self._due_date.year) and (self._return_date.month < self._due_date.month)) or \
            ((self._return_date.year == self._due_date.year) and (self._return_date.month == self._due_date.month) and (self._return_date.day <= self._due_date.day)):
            return True
        return False


    def _is_return_date_late_in_more_than_or_equal_to_one_year(self):

        return self._return_date.year > self._due_date.year


    def _is_return_date_late_in_more_than_or_equal_to_one_month(self):

        return self._return_date.month > self._due_date.month


    def fine(self):

        return self._fine


class HackosFine(Enum):

    hackos_days_fine = 15
    hackos_months_fine = 500
    hackos_years_fine = 10000


if __name__ == '__main__':
    main()
