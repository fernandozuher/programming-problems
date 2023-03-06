# Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main
    input = readInput
    input = reduceInputRotations input
    input = rotateInputArray input
    printRotatedArrayElementsAccordingToQueries input
end

    def readInput
        arraySize, rotationCount, queriesSize = readLineAsIntList
        array = readLineAsIntList
        queries = readQueries queriesSize
        input = [array, arraySize, rotationCount, queries, queriesSize]
    end

        def readLineAsIntList
            array = gets.split.map(&:to_i)
        end

        def readQueries size
            array = Array.new(size) { |element| gets.to_i }
        end

    def reduceInputRotations input
        arraySize = input[1]
        rotationCount = input[2]

        if (arraySize > 1)
            input[2] = rotationCount = rotationCount >= arraySize ? rotationCount % arraySize : rotationCount
        else
            input[2] = rotationCount = 0
        end

        input
    end

    def rotateInputArray input
        array = input[0]
        arraySize = input[1]
        rotationCount = input[2]

        firstPartNewArray = array[arraySize - rotationCount...]
        secondPartNewArray = array[...arraySize - rotationCount]
        newArray = firstPartNewArray + secondPartNewArray

        input[0] = newArray
        input
    end

    def printRotatedArrayElementsAccordingToQueries input
        array = input[0]
        queries = input[3]
        queries.each { |query| puts array[query] }
    end

main
