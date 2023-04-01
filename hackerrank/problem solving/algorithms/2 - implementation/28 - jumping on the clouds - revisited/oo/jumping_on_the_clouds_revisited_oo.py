# Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

def main():

    array = readAnArray()
    _SIZE_ARRAY = array[0]
    JUMP_LENGTH = array[1]
    array = readAnArray()

    OBJ = JumpingOnTheClouds(array, JUMP_LENGTH)
    print(OBJ.getRemainingEnergy())


def readAnArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


class JumpingOnTheClouds:

    def __init__(self, ARRAY, JUMP_LENGTH):

        self.__array = ARRAY
        self.__jumpLength = JUMP_LENGTH
        self.__energy = 100

        self.__jumpOnClouds()


    def __jumpOnClouds(self):

        cloudIndex = 0
        while True:
            self.__energy -= self.__spentEnergyAccordingToTypeOfCloud(self.__array[cloudIndex])
            cloudIndex = self.__generateNewCloudIndex(cloudIndex)
            if self.__isCloudIndexBackToFirstCloud(cloudIndex):
                break


    def __spentEnergyAccordingToTypeOfCloud(self, cloudType):

        return 1 if cloudType == 0 else 3


    def __generateNewCloudIndex(self, cloudIndex):

        return (cloudIndex + self.__jumpLength) % len(self.__array)


    def __isCloudIndexBackToFirstCloud(self, cloudIndex):

        return cloudIndex == 0


    def getRemainingEnergy(self):

        return self.__energy


if __name__ == "__main__":
    main()
