# Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main():

    N_TEST_CASES = readANumber()
    output = [None] * N_TEST_CASES

    for i in range(0, N_TEST_CASES):
        NUMBER = readANumber()
        OBJ = FindDigits(NUMBER)
        output[i] = OBJ.getDivisors()

    printOutput(output)


def readANumber():

    NUMBER = int(input())
    return NUMBER


def printOutput(array):

    print(*array, sep="\n")


class FindDigits:

    def __init__(self, number):

        self.__number = number
        self.__divisors = 0
        self.__findNumberDivisorsQuantity()


    def __findNumberDivisorsQuantity(self):

        currentNumber = self.__number

        while currentNumber != 0:
            DIVISOR = self.__getLastDigitOfNumber(currentNumber)
            if self.__isNumberEvenlyDividedByDivisor(DIVISOR):
                self.__divisors += 1
            currentNumber = self.__removeLastDigitOfNumber(currentNumber)


    def __getLastDigitOfNumber(self, NUMBER):

        return int(NUMBER % 10)


    def __isNumberEvenlyDividedByDivisor(self, DIVISOR):

        return DIVISOR != 0 and self.__number % DIVISOR == 0


    def __removeLastDigitOfNumber(self, NUMBER):

        return int(NUMBER / 10)


    def getDivisors(self):

        return self.__divisors;


if __name__ == "__main__":
    main()
