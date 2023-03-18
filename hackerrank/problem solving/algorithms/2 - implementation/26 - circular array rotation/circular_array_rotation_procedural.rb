# Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main
    input = readInput
    obj = CircularArrayRotation.new input
    obj.printRotatedArrayElementsAccordingToQueries
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

    class CircularArrayRotation
        @array
        @arraySize
        @rotationCount
        @queries
        @querySize

        def initialize input
            @array = input.first
            @arraySize = input[1]
            @rotationCount = input[2]
            @queries = input[3]
            @querySize = input.last

            _reduceInputRotations
            _rotateInputArray
        end

            private def _reduceInputRotations
                if (@arraySize > 1)
                    @rotationCount = @rotationCount >= @arraySize ? @rotationCount % @arraySize : @rotationCount
                else
                    @rotationCount = 0
                end
            end

            private def _rotateInputArray
                firstPartNewArray = @array[@arraySize - @rotationCount...@arraySize]
                secondPartNewArray = @array[0...@arraySize - @rotationCount]
                newArray = firstPartNewArray + secondPartNewArray

                @array = newArray
            end

        def printRotatedArrayElementsAccordingToQueries
            @queries.each { |query| puts @array[query] }
        end
    end

main
