# Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

def main
    nTestCases = gets.to_i
    output = Array.new nTestCases

    output.map! { |element|
        beginRange, endRange = readAnArray
        element = calculateNumberOfSquareIntegersInRange beginRange, endRange
    }

    puts output
end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    def calculateNumberOfSquareIntegersInRange beginRange, endRange
        squares = 0
        number = findFirstSquareIntegerFromNumber beginRange

        while isPowerOf2OfNumberLessThanOrEqualToLimit number, endRange
            squares += 1
            number += 1
        end

        squares
    end

        def findFirstSquareIntegerFromNumber number
            squareRootNumber = Math.sqrt number
            squareInteger = getSquareIntegerFromNumber squareRootNumber
        end

            def getSquareIntegerFromNumber number
                integerPart = number.truncate
                number == integerPart ? integerPart : integerPart + 1
            end

        def isPowerOf2OfNumberLessThanOrEqualToLimit number, limit
            number.pow(2) <= limit
        end

main
