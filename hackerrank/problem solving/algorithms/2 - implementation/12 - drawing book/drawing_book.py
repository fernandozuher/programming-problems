#!/bin/python

# Source: https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true


def main():

    pageQuantity = readLineAsIntList()
    page = readLineAsIntList()

    result = Result(pageQuantity[0], page[0])


def readLineAsIntList():

    numbers = list(map(int, input().split()))
    return numbers


class Result:

    def __init__(self, pageQuantity, page):
        
        self.__pageQuantity = pageQuantity
        self.__page = page
        self.__turnOfPagesFromFront = 0
        self.__turnOfPagesFromBack = 0
        self.__minimumTurnOfPages = 0

        self.__drawingBook()
        self.printResult()


    def __drawingBook(self):

        self.__turnOfPagesFromFront = self.__calculateTurnOfPages(self.__page)
        
        maximumTurns = self.__calculateTurnOfPages(self.__pageQuantity)

        self.__turnOfPagesFromBack = maximumTurns - self.__turnOfPagesFromFront

        self.__minimumTurnOfPages = int(min(self.__turnOfPagesFromFront, self.__turnOfPagesFromBack))


    def __calculateTurnOfPages(self, page):

        return self.__pageIsOdd(page) if page & 1 else self.__pageIsEven(page)


    def __pageIsOdd(self, page):

        return (page - 1) / 2


    def __pageIsEven(self, page):

        return page / 2


    def printResult(self):
        
        print(self.__minimumTurnOfPages)


if __name__ == "__main__":
    main()
