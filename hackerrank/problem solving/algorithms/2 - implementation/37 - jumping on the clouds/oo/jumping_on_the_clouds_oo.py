# Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

def main():

    _ = int(input())
    CLOUD_ARRAY = readAnArray()

    OBJ = JumpingOnTheClouds(CLOUD_ARRAY)
    MINIMUM_NUMBER_OF_JUMPS = OBJ.getMinimumNumberOfJumps()
    print(MINIMUM_NUMBER_OF_JUMPS)


def readAnArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


class JumpingOnTheClouds:

    def __init__(self, cloudArray):

        self.__cloudArray = cloudArray
        self.__minimumNumberOfJumps = 0

        self.__calculateMinimumNumberOfJumps()


    def __calculateMinimumNumberOfJumps(self):

        i = 0
        size = len(self.__cloudArray) - 1

        while i < size:
            i = self.__getIndexOfNextJump(i)
            self.__minimumNumberOfJumps += 1


    def __getIndexOfNextJump(self, index):

        if self.__isNextSecondIndexInsideRange(index + 2):
            index += 2 if self.__isNextSecondCloudCumulus(self.__cloudArray[index + 2]) else 1
        else:
            index += 1
        return index


    def __isNextSecondIndexInsideRange(self, index):

        return index < len(self.__cloudArray)


    def __isNextSecondCloudCumulus(self, typeOfCloud):

        return typeOfCloud == 0


    def getMinimumNumberOfJumps(self):

        return self.__minimumNumberOfJumps


if __name__ == "__main__":
    main()
