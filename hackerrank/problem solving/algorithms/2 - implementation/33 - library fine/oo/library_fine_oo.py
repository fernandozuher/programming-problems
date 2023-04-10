# Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

from enum import Enum
from datetime import datetime

class HackosFine(Enum):
    HackosDaysFine = 15
    HackosMonthsFine = 500
    HackosYearsFine = 10000


def main():

    RETURN_DATE = readADate()
    DUE_DATE = readADate()

    OBJ = LibrayFine(RETURN_DATE, DUE_DATE)
    FINE = OBJ.getFine()
    print(FINE)


def readADate():

    DAY, MONTH, YEAR = map(int, input().split())
    DATE = datetime(YEAR, MONTH, DAY)
    return DATE


class LibrayFine:
    
    def __init__(self, returnDate, dueDate):

        self.__RETURN_DATE = returnDate
        self.__DUE_DATE = dueDate
        self.__fine = 0

        self.__calculateFine()


    def __calculateFine(self):

        if self.__wereBooksReturnedInTime():
            self.__fine = 0
        elif self.__isReturnDateLateInMoreThanOrEqualToOneYear():
            self.__fine = HackosFine.HackosYearsFine.value
        elif self.__isReturnDateLateInMoreThanOrEqualToOneMonth():
            self.__fine = (self.__RETURN_DATE.month - self.__DUE_DATE.month) * HackosFine.HackosMonthsFine.value
        else:
            self.__fine = (self.__RETURN_DATE.day - self.__DUE_DATE.day) * HackosFine.HackosDaysFine.value


    def __wereBooksReturnedInTime(self):

        if (self.__RETURN_DATE.year < self.__DUE_DATE.year) or \
            ((self.__RETURN_DATE.year == self.__DUE_DATE.year) and (self.__RETURN_DATE.month < self.__DUE_DATE.month)) or \
            ((self.__RETURN_DATE.year == self.__DUE_DATE.year) and (self.__RETURN_DATE.month == self.__DUE_DATE.month) and (self.__RETURN_DATE.day <= self.__DUE_DATE.day)):
            return True
        return False


    def __isReturnDateLateInMoreThanOrEqualToOneYear(self):

        return self.__RETURN_DATE.year > self.__DUE_DATE.year


    def __isReturnDateLateInMoreThanOrEqualToOneMonth(self):

        return self.__RETURN_DATE.month > self.__DUE_DATE.month


    def getFine(self):

        return self.__fine


if __name__ == "__main__":
    main()
