# Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main
    size = readANumber
    array = readAnArray

    obj = SequenceEquation.new array
    obj.printPermutatedArray
end

    def readANumber
        gets.to_i
    end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    class SequenceEquation

        def initialize array
            @inputArray = array
            @elementsPositionsArray = _generateElementsPositionsArray
            @permutatedArray = _generatePermutatedArray
        end

            def _generateElementsPositionsArray
                elementsPositionsArray = Array.new(@inputArray .size)
                @inputArray .each_with_index { |element, i|
                    elementsPositionsArray[element-1] = i
                }
                elementsPositionsArray
            end

            def _generatePermutatedArray
                permutatedArray = Array.new(@elementsPositionsArray.size)
                @elementsPositionsArray.each_with_index { |element, i|
                    permutatedArray[i] = @elementsPositionsArray[element] + 1
                }
                permutatedArray
            end

        def printPermutatedArray
            puts @permutatedArray
        end
    end

main
