# Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

def main
    _ = gets.to_i
    cloudArray = readAnArray
    minimumNumberOfJumps = calculateMinimumNumberOfJumps cloudArray
    puts minimumNumberOfJumps
end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    def calculateMinimumNumberOfJumps array
        i = 0
        size = array.size - 1
        jumps = 0

        while i < size
            i = getIndexOfNextJump i, array
            jumps += 1
        end

        jumps
    end

        def getIndexOfNextJump index, array
            if isNextSecondIndexInsideRange(index + 2, array.size)
                index += isNextSecondCloudCumulus(array[index + 2]) ? 2 : 1
            else
                index += 1
            end
            return index
        end

            def isNextSecondIndexInsideRange index, size
                index < size
            end

            def isNextSecondCloudCumulus typeOfCloud
                typeOfCloud == 0
            end

main
