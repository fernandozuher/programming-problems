#!/bin/python3

# Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

def main():

    readLineAsIntList()
    ranked = readLineAsIntList()

    readLineAsIntList()
    player = readLineAsIntList()

    result = Result(ranked, player)


def readLineAsIntList():

    inputLine = list(map(int, input().split()))
    return inputLine


class Result:

    def __init__(self, ranked, player):

        self.__ranked = ranked.copy()
        self.__player = player.copy()
        self.__playerRank = [None] * len(player)

        self.__removeDuplicatesFromRankedList()
        self.__climbingLeaderboard()
        self.printResult()


    def __removeDuplicatesFromRankedList(self):

        self.__ranked = list(dict.fromkeys(self.__ranked))


    def __climbingLeaderboard(self):

        for i, playerScore in enumerate(self.__player):
            index = self.__binarySearchDescendingOrder(0, len(self.__ranked) - 1, playerScore)
            self.__playerRank[i] = index + 1


    def __binarySearchDescendingOrder(self, low, high, key):

        if high >= low:
            middle = low + int((high - low) / 2)

            if key == self.__ranked[middle]:
                return middle
            elif key > self.__ranked[middle]:
                return self.__binarySearchDescendingOrder(low, middle - 1, key)
            else:
                return self.__binarySearchDescendingOrder(middle + 1, high, key)
        return low


    def printResult(self):

        for playerRank in self.__playerRank:
            print(playerRank)


if __name__ == "__main__":
    main()
