# Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

def main
    nTestCases = gets.to_i
    output = Array.new nTestCases

    output.map! {|element|
        beginRange, endRange = readAnArray
        obj = SherlockAndSquares.new beginRange, endRange
        element = obj.getQuantityOfSquareIntegers
    }

    puts output
end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    class SherlockAndSquares
        @beginRange
        @endRange
        @quantityOfSquareIntegers

        def initialize beginRange, endRange
            @beginRange = beginRange
            @endRange = endRange
            @quantityOfSquareIntegers = 0

            _calculateNumberOfSquareIntegersInRange
        end

            private def _calculateNumberOfSquareIntegersInRange
                number = _findFirstSquareIntegerFromBeginNumber
                while _isPowerOf2OfNumberLessThanOrEqualToEndNumber number
                    @quantityOfSquareIntegers += 1
                    number += 1
                end
            end

                private def _findFirstSquareIntegerFromBeginNumber
                    squareRootNumber = Math.sqrt @beginRange
                    squareInteger = _getSquareIntegerFromNumber squareRootNumber
                end

                    private def _getSquareIntegerFromNumber number
                        integerPart = number.truncate
                        number == integerPart  ? integerPart : integerPart + 1
                    end

            private def _isPowerOf2OfNumberLessThanOrEqualToEndNumber number
                number.pow(2) <= @endRange
            end

        def getQuantityOfSquareIntegers
            @quantityOfSquareIntegers
        end
    end

main
