from enum import Enum
import datetime

class HackosFine(Enum):
    HackosDaysFine = 15
    HackosMonthsFine = 500
    HackosYearsFine = 10000

class BookReturnDate:
    def __init__(self, returnedRealDate, dueDate):
        self.returnedRealDate, self.dueDate = returnedRealDate, dueDate
        self.fine = None
        self.__calculateFine()

    def __calculateFine(self):
        if self.returnedRealDate <= self.dueDate:
            self.fine = 0
        elif self.returnedRealDate.year == self.dueDate.year:
            if self.returnedRealDate.month == self.dueDate.month:
                self.fine = (self.returnedRealDate.day - self.dueDate.day) * HackosFine.HackosDaysFine.value
            else:
                self.fine = (self.returnedRealDate.month - self.dueDate.month) * HackosFine.HackosMonthsFine.value
        else:
            self.fine = HackosFine.HackosYearsFine.value
        return self.fine

    def getFine(self):
        return self.fine

def readStdinDates():
    day1, month1, year1 = map(int, input().split())
    day2, month2, year2 = map(int, input().split())

    returnedRealDate = datetime.datetime(year1, month1, day1)
    dueDate = datetime.datetime(year2, month2, day2)

    return [returnedRealDate, dueDate]

def main():
    returnedRealDate, dueDate = readStdinDates()
    bookReturnDateObj = BookReturnDate(returnedRealDate, dueDate)
    print(bookReturnDateObj.getFine())

if __name__ == "__main__":
    main()
