# Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main
    size = readANumber
    array = readAnArray

    permutatedArray = permutationEquation array
    printArray permutatedArray
end

    def readANumber
        gets.to_i
    end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    def permutationEquation array
        arrayElementsPositions = generateArrayOfElementsPositions array
        permutatedArray = generatePermutatedArray arrayElementsPositions
    end

        def generateArrayOfElementsPositions array
            arrayElementsPositions = Array.new(array.size)
            array.each_with_index { |element, i|
                arrayElementsPositions[element-1] = i
            }
            arrayElementsPositions
        end

        def generatePermutatedArray array
            permutatedArray = Array.new(array.size)
            array.each_with_index { |element, i|
                permutatedArray[i] = array[element] + 1
            }
            permutatedArray
        end

    def printArray array
        puts array
    end

main
