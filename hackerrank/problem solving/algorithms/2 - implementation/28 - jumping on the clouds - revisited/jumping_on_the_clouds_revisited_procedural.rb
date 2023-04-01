# Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

def main
    array = readAnArray
    sizeArray = array.first
    jumpLength = array.last
    array = readAnArray

    energy = jumpingOnClouds array, jumpLength
    puts energy
end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    def jumpingOnClouds array, jumpLength
        energy = 100

        cloudIndex = 0
        while true
            energy -= spentEnergyAccordingToTypeOfCloud array[cloudIndex]
            cloudIndex = generateNewCloudIndex cloudIndex, array.size, jumpLength
            if isCloudIndexBackToFirstCloud cloudIndex
                break
            end
        end

        energy
    end

        def spentEnergyAccordingToTypeOfCloud cloudType
            cloudType == 0 ? 1 : 3
        end

        def generateNewCloudIndex cloudIndex, sizeArray, jumpLength
            (cloudIndex + jumpLength) % sizeArray
        end

        def isCloudIndexBackToFirstCloud cloudIndex
            cloudIndex == 0
        end

main
