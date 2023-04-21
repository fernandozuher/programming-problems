# Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

def main
    _ = gets
    array = readAnArray

    minimumNumberOfDeletionsRequired = equalizeArray array
    puts minimumNumberOfDeletionsRequired
end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    def equalizeArray array
        array = array.sort
        maximumQuantityOfEqualElement = findMaximumQuantityOfEqualElement array
        minimumNumberOfDeletionsRequired = array.size - maximumQuantityOfEqualElement
    end

        def findMaximumQuantityOfEqualElement array
            maximumQuantityOfEqualElement = 1
            temporaryQuantityEqualElement = 1

            for i in 1..(array.size-1)
                if areConsecutiveElementesEqual array[i-1], array[i]
                    temporaryQuantityEqualElement += 1
                    maximumQuantityOfEqualElement = [temporaryQuantityEqualElement, maximumQuantityOfEqualElement].max
                else
                    temporaryQuantityEqualElement = 1
                end
            end

            maximumQuantityOfEqualElement
        end

            def areConsecutiveElementesEqual element1, element2
                element1 == element2
            end

main
