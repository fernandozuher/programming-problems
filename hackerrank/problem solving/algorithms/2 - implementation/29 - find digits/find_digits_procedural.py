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
        POTENTIAL_DIVISOR = int(number % 10)
        if isNumberEvenlyDividedByDivisor(NUMBER, POTENTIAL_DIVISOR):
            divisors += 1
        number = int(number / 10)

    return divisors


def isNumberEvenlyDividedByDivisor(NUMBER, DIVISOR):

    return DIVISOR != 0 and NUMBER % DIVISOR == 0


def printOutput(array):

    print(*array, sep="\n")


if __name__ == "__main__":
    main()
