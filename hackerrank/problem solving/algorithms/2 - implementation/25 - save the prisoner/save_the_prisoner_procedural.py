# Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main():

    N_TEST_CASES = readANumber()
    PRISONERS_CHAIR_NUMBER_TO_WARN = readTestCasesAndSaveThePrisoners(N_TEST_CASES)
    printResults(PRISONERS_CHAIR_NUMBER_TO_WARN)


def readANumber():

    number = int(input())
    return number


def readTestCasesAndSaveThePrisoners(nTestCases):

    prisonersChairNumberToWarn = [None] * nTestCases

    for i in range(nTestCases):
        TEST_CASE = readTestCase()
        prisonersChairNumberToWarn[i] = saveThePrisoner(TEST_CASE)

    return prisonersChairNumberToWarn


def readTestCase():

    TEST_CASE = list(map(int, input().split()))
    return TEST_CASE


def saveThePrisoner(testCase):

    PRISONERS = testCase[0]
    SWEETS = testCase[1]
    CHAIR_NUMBER_TO_BEGIN = testCase[2]
    prisonerChairNumberToWarn = CHAIR_NUMBER_TO_BEGIN + (SWEETS - 1)

    if prisonerChairNumberToWarn > PRISONERS:
        prisonerChairNumberToWarn %= PRISONERS

        if prisonerChairNumberToWarn == 0:
            prisonerChairNumberToWarn = PRISONERS

    return prisonerChairNumberToWarn


def printResults(ARRAY):

    for element in ARRAY:
        print(element)


if __name__ == "__main__":
    main()
