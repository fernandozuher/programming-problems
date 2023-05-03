# Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

def main():

    LOWER_LIMIT = int(input())
    UPPER_LIMIT = int(input())

    OUTPUT = findKaprekarNumbersInRange(LOWER_LIMIT, UPPER_LIMIT)
    printOutput(OUTPUT)


def findKaprekarNumbersInRange(LOWER_LIMIT, UPPER_LIMIT):

    kaprekarNumbers = []

    for number in range(LOWER_LIMIT, UPPER_LIMIT + 1):
        POTENTIAL_KAPREKAR_NUMBER = calculatePotentialKaprekarNumber(number)
        if number == POTENTIAL_KAPREKAR_NUMBER:
            kaprekarNumbers.append(number)

    return kaprekarNumbers


def calculatePotentialKaprekarNumber(number):

    SQUARE_NUMBER_IN_STRING = str(pow(number, 2))
    SIZE_OF_STRING = len(str(number))

    LEFT_NUMBER_IN_STRING = getLeftNumberInString(SQUARE_NUMBER_IN_STRING, SIZE_OF_STRING)
    RIGHT_NUMBER_IN_STRING = getRightNumberInString(SQUARE_NUMBER_IN_STRING, SIZE_OF_STRING)

    POTENTIAL_KAPREKAR_NUMBER = sumNumbersInStrings(LEFT_NUMBER_IN_STRING, RIGHT_NUMBER_IN_STRING)

    return POTENTIAL_KAPREKAR_NUMBER


def getLeftNumberInString(SQUARE_NUMBER_IN_STRING, SIZE_OF_STRING):

    DIGITS_TO_SKIP = 0
    DIGITS_TO_TAKE = len(SQUARE_NUMBER_IN_STRING) - SIZE_OF_STRING
    NUMBER_IN_STRING = SQUARE_NUMBER_IN_STRING[DIGITS_TO_SKIP : DIGITS_TO_TAKE]
    return NUMBER_IN_STRING


def getRightNumberInString(SQUARE_NUMBER_IN_STRING, SIZE_OF_STRING):

    DIGITS_TO_SKIP = len(SQUARE_NUMBER_IN_STRING) - SIZE_OF_STRING
    NUMBER_IN_STRING = SQUARE_NUMBER_IN_STRING[DIGITS_TO_SKIP:]
    return NUMBER_IN_STRING


def sumNumbersInStrings(LEFT_NUMBER_IN_STRING, RIGHT_NUMBER_IN_STRING):

    if len(LEFT_NUMBER_IN_STRING) > 0 and len(RIGHT_NUMBER_IN_STRING) > 0:
        return int(LEFT_NUMBER_IN_STRING) + int(RIGHT_NUMBER_IN_STRING)
    elif len(LEFT_NUMBER_IN_STRING) == 0:
        return int(RIGHT_NUMBER_IN_STRING)
    elif len(RIGHT_NUMBER_IN_STRING) == 0:
        return int(LEFT_NUMBER_IN_STRING)

    return 0


def printOutput(ARRAY):

    if len(ARRAY) > 0:
        print(*ARRAY, sep=" ")
    else:
        print("INVALID RANGE")


if __name__ == "__main__":
    main()
