# https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

from enum import Enum
import datetime

def main():

    returned_real_date, due_date = read_stdin_dates()
    book_return_date = BookReturnDate(returned_real_date, due_date)
    print(book_return_date.fine())


def read_stdin_dates():

    day1, month1, year1 = map(int, input().split())
    day2, month2, year2 = map(int, input().split())

    returned_real_date = datetime.datetime(year1, month1, day1)
    due_date = datetime.datetime(year2, month2, day2)

    return [returned_real_date, due_date]


class BookReturnDate:

    def __init__(self, returned_real_date, due_date):

        self._returned_real_date, self._due_date = returned_real_date, due_date
        self._fine = 0
        self._calculate_fine()


    def _calculate_fine(self):

        if self._returned_real_date <= self._due_date:
            self._fine = 0
        elif self._returned_real_date.year == self._due_date.year:
            if self._returned_real_date.month == self._due_date.month:
                self._fine = (self._returned_real_date.day - self._due_date.day) * HackosFine.hackos_days_fine.value
            else:
                self._fine = (self._returned_real_date.month - self._due_date.month) * HackosFine.hackos_months_fine.value
        else:
            self._fine = HackosFine.hackos_years_fine.value
        return self._fine


    def fine(self):

        return self._fine


class HackosFine(Enum):

    hackos_days_fine = 15
    hackos_months_fine = 500
    hackos_years_fine = 10000


if __name__ == "__main__":
    main()
