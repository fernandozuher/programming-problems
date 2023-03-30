# Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

def main():

    array = readAnArray()
    _SIZE_ARRAY = array[0]
    JUMP_LENGTH = array[1]
    array = readAnArray()

    ENERGY = jumpingOnClouds(array, JUMP_LENGTH)
    print(ENERGY)


def readAnArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


def jumpingOnClouds(array, jumpLength):

    energy = 100

    cloudIndex = 0
    while True:
        energy -= spentEnergyAccordingToTypeOfCloud(array[cloudIndex])
        cloudIndex = generateNewCloudIndex(cloudIndex, len(array), jumpLength)
        if isCloudIndexBackToFirstCloud(cloudIndex):
            break

    return energy


def spentEnergyAccordingToTypeOfCloud(cloudType):

    return 1 if cloudType == 0 else 3


def generateNewCloudIndex(cloudIndex, sizeArray, jumpLength):

    return (cloudIndex + jumpLength) % sizeArray


def isCloudIndexBackToFirstCloud(cloudIndex):

    return cloudIndex == 0


if __name__ == "__main__":
    main()
