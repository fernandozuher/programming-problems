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
        elementsPositionsArray = generateElementsPositionsArray array
        permutatedArray = generatePermutatedArray elementsPositionsArray
    end

        def generateElementsPositionsArray array
            elementsPositionsArray = Array.new(array.size)
            array.each_with_index { |element, i|
                elementsPositionsArray[element-1] = i
            }
            elementsPositionsArray
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
