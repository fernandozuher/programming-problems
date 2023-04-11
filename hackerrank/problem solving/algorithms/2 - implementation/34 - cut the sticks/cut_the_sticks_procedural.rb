# Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main
    _size = readANumber
    array = readAnArray
    array = array.sort

    result = cutTheSticks array
    puts result
end

    def readANumber
        gets.to_i
    end

    def readAnArray()
        gets.split.map(&:to_i)
    end

    def cutTheSticks array
        size = array.size
        remainingSticksOfEachIteration = initializeResult size

        i = 0
        while i < size
            shortestStickLength = array[i]

            i = findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex i, array
            currentIterationSize = size - i
            if i == size
                break
            end

            remainingSticksOfEachIteration.append currentIterationSize
            decreaseSticksLengthsHigherThanCurrentShortestStickLength i, array, shortestStickLength
        end
        
        remainingSticksOfEachIteration
    end

        def initializeResult size
            remainingSticksOfEachIteration = [size]
        end

        def findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex index, array
            size = array.size
            shortestStickLength = array[index]

            while index < size and array[index] == shortestStickLength
                index += 1
            end

            index
        end

        def decreaseSticksLengthsHigherThanCurrentShortestStickLength index, array, shortestStickLength
            for i in index..(array.size-1)
                array[i] -= shortestStickLength
            end
        end

main
