# Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main():

    N_TEST_CASES = readANumber()
    output = [None] * N_TEST_CASES

    for i in range(0, N_TEST_CASES):
        NUMBER = readANumber()
        output[i] = findNumberDivisorsQuantity(NUMBER)

    printOutput(output)


def readANumber():

    NUMBER = int(input())
    return NUMBER


def findNumberDivisorsQuantity(NUMBER):

    number = NUMBER
    divisors = 0

    while number != 0:
        DIVISOR = getLastDigitOfNumber(number)
        if isNumberEvenlyDividedByDivisor(NUMBER, DIVISOR):
            divisors += 1
        number = removeLastDigitOfNumber(number)

    return divisors


def getLastDigitOfNumber(NUMBER):

    return int(NUMBER % 10)


def isNumberEvenlyDividedByDivisor(NUMBER, DIVISOR):

    return DIVISOR != 0 and NUMBER % DIVISOR == 0


def removeLastDigitOfNumber(NUMBER):

    return int(NUMBER / 10)


def printOutput(array):

    print(*array, sep="\n")


if __name__ == "__main__":
    main()
