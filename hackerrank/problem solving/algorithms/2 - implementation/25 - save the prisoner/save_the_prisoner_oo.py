# Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main():

    N_TEST_CASES = readANumber()
    prisonersChairNumberToWarn = [None] * N_TEST_CASES

    for i in range(N_TEST_CASES):
        TEST_CASE = readTestCase()
        OBJ = SaveThePrisoner(TEST_CASE)
        prisonersChairNumberToWarn[i] = OBJ.getPrisonerChairNumberToWarn()

    printResults(prisonersChairNumberToWarn)


def readANumber():

    number = int(input())
    return number


def readTestCase():

    TEST_CASE = list(map(int, input().split()))
    return TEST_CASE


class SaveThePrisoner:

    def __init__(self, testCase):

        self.__prisoners = testCase[0]
        self.__sweets = testCase[1]
        self.__chairNumberToBegin = testCase[2]

        self.__prisonerChairNumberToWarn = self.__saveThePrisoner()


    def __saveThePrisoner(self):

        prisonerChairNumberToWarn = self.__chairNumberToBegin + (self.__sweets - 1)

        if prisonerChairNumberToWarn > self.__prisoners:
            prisonerChairNumberToWarn %= self.__prisoners

            if prisonerChairNumberToWarn == 0:
                prisonerChairNumberToWarn = self.__prisoners

        return prisonerChairNumberToWarn


    def getPrisonerChairNumberToWarn(self):

        return self.__prisonerChairNumberToWarn


def printResults(ARRAY):

    [print(element) for element in ARRAY]


if __name__ == "__main__":
    main()
