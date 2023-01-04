#!/bin/python3

# Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main():

    readLineAsIntList()
    socks = readLineAsIntList()

    result = Result(socks)


def readLineAsIntList():

    numbers = list(map(int, input().split()))
    return numbers


class Result:

    def __init__(self, socks):
        
        self.__socks = socks
        self.__pairs = 0

        self.__sockMerchant()
        self.printResult()


    def __sockMerchant(self):

        socksPairing = {}

        for sock in self.__socks:
            if socksPairing.get(sock):
                self.__pairs += 1
            socksPairing[sock] = not socksPairing[sock] if socksPairing.get(sock) != None else True


    def printResult(self):
        
        print(self.__pairs)


if __name__ == "__main__":
    main()
