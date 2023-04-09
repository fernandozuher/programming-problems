# Source: 

from enum import Enum
from datetime import datetime

class HackosFine(Enum):
    HackosDaysFine = 15
    HackosMonthsFine = 500
    HackosYearsFine = 10000


def main():

    RETURN_DATE = readADate()
    DUE_DATE = readADate()

    FINE = calculate_fine(RETURN_DATE, DUE_DATE)
    print(FINE)


def readADate():

    DAY, MONTH, YEAR = map(int, input().split())
    DATE = datetime(YEAR, MONTH, DAY)
    return DATE


def calculate_fine(returnDate, dueDate):

    fine = 0

    if wereBooksReturnedInTime(returnDate, dueDate):
        fine = 0
    elif isReturnDateLateInMoreThanOrEqualToOneYear(returnDate.year, dueDate.year):
        fine = HackosFine.HackosYearsFine.value
    elif isReturnDateLateInMoreThanOrEqualToOneMonth(returnDate.month, dueDate.month):
        fine = (returnDate.month - dueDate.month) * HackosFine.HackosMonthsFine.value
    else:
        fine = (returnDate.day - dueDate.day) * HackosFine.HackosDaysFine.value

    return fine


def wereBooksReturnedInTime(returnDate, dueDate):

    if (returnDate.year < dueDate.year) or \
        ((returnDate.year == dueDate.year) and (returnDate.month < dueDate.month)) or \
        ((returnDate.year == dueDate.year) and (returnDate.month == dueDate.month) and (returnDate.day <= dueDate.day)):
        return True
    return False


def isReturnDateLateInMoreThanOrEqualToOneYear(returnDateYear, dueDateYear):

    return returnDateYear > dueDateYear


def isReturnDateLateInMoreThanOrEqualToOneMonth(returnDateMonth, dueDateMonth):

    return returnDateMonth > dueDateMonth


if __name__ == "__main__":
    main()
