# Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main
    nTestCases = readANumber
    output = Array.new(nTestCases)

    for i in (0..nTestCases-1)
        number = readANumber
        obj = FindDigits.new number
        output[i] = obj.getDivisors
    end

    printOutput output
end

    def readANumber
        number = gets.to_i
    end

    def printOutput array
        puts array
    end

    class FindDigits
        @number
        @divisors

        def initialize number
            @number = number
            @divisors = 0
            _findNumberDivisorsQuantity
        end

            def _findNumberDivisorsQuantity
                currentNumber = @number

                while currentNumber != 0
                    divisor = _getLastDigitOfNumber currentNumber
                    if _isNumberEvenlyDividedByDivisor divisor
                        @divisors += 1
                    end
                    currentNumber = _removeLastDigitOfNumber currentNumber
                end
            end

                def _getLastDigitOfNumber number
                    (number % 10).to_i
                end

                def _isNumberEvenlyDividedByDivisor divisor
                    divisor != 0 and @number % divisor == 0
                end

                def _removeLastDigitOfNumber number
                    (number / 10).to_i
                end

        def getDivisors
            @divisors
        end
    end

main
