#!/bin/python3

# Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

def main():

    year = readLineAsIntList();

    result = Result(year[0]);


def readLineAsIntList():

    numbers = list(map(int, input().split()))
    return numbers


class Result:

    def __init__(self, year):
        
        self.__year = year
        self.__date = ""

        self.__dayOfProgrammer()
        self.printResult()


    def __dayOfProgrammer(self):

        if self.__year != 1918:
            isLeap = self.isLeapGregorianYear() if self.__year > 1918 else self.isLeapJulianYear()
            self.__date = "12.09." if isLeap else "13.09."
        else:
            self.__date = "26.09."

        self.__date += str(self.__year)
    

    def isLeapGregorianYear(self):

        return (not (self.__year % 400)) or (not (self.__year % 4) and self.__year % 100)
        

    def isLeapJulianYear(self):

        return not (self.__year % 4)


    def printResult(self):
        
        print(self.__date)


if __name__ == "__main__":
    main()
