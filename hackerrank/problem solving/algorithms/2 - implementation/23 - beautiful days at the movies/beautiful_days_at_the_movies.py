# Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

def main():

    [startingDayNumber, endingDayNumber, divisor] = readLineAsIntList()
    beautifulDays = BeautifulDays(startingDayNumber, endingDayNumber, divisor)


def readLineAsIntList():

    inputLine = list(map(int, input().split()))
    return inputLine


class BeautifulDays:

    def __init__(self, startingDayNumber, endingDayNumber, divisor):

        self.__startingDayNumber = startingDayNumber
        self.__endingDayNumber = endingDayNumber
        self.__divisor = divisor
        self.__nBeautifulDays = 0

        self.__beautifulDays()
        self.printNBeautifulDays()


    def __beautifulDays(self):

        for number in range(self.__startingDayNumber, self.__endingDayNumber + 1):
            reverseNumber = self.__generateReverseNumber(number)

            if self.__isDayBeautiful(number, reverseNumber):
                self.__nBeautifulDays += 1


    def __generateReverseNumber(self, number):

        reverseNumber = 0

        while number > 0:
            reverseNumber = (reverseNumber * 10) + (number % 10)
            number = int(number / 10)

        return reverseNumber


    def __isDayBeautiful(self, number, reverseNumber):

        beautifulDay = abs(number - reverseNumber) % self.__divisor == 0
        return beautifulDay


    def printNBeautifulDays(self):

        print(self.__nBeautifulDays)


if __name__ == "__main__":
    main()
