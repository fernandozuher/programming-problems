# Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main
    nTestCases = readANumber
    output = Array.new(nTestCases)

    for i in (0..nTestCases-1)
        number = readANumber
        output[i] = findNumberDivisorsQuantity number
    end

    printOutput output
end

    def readANumber
        number = gets.to_i
    end

    def findNumberDivisorsQuantity number
        currentNumber = number
        divisors = 0

        while currentNumber != 0
            divisor = getLastDigitOfNumber currentNumber
            if isNumberEvenlyDividedByDivisor number, divisor
                divisors += 1
            end
            currentNumber = removeLastDigitOfNumber currentNumber
        end

        divisors
    end

        def getLastDigitOfNumber number
            (number % 10).to_i
        end

        def isNumberEvenlyDividedByDivisor number, divisor
            divisor != 0 and number % divisor == 0
        end

        def removeLastDigitOfNumber number
            (number / 10).to_i
        end

    def printOutput array
        puts array
    end

main
