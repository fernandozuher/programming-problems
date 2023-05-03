# Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

def main
    lowerLimit = gets.to_i
    upperLimit = gets.to_i

    output = findKaprekarNumbersInRange lowerLimit, upperLimit
    printOutput output
end

    def findKaprekarNumbersInRange lowerLimit, upperLimit
        kaprekarNumbers = Array.new

        for number in lowerLimit..upperLimit
            potentialKaprekarNumber = calculatePotentialKaprekarNumber number
            if number == potentialKaprekarNumber
                kaprekarNumbers.append(number)
            end
        end

        kaprekarNumbers
    end

        def calculatePotentialKaprekarNumber number
            squareNumberInString = number.pow(2).to_s
            sizeOfString = number.to_s.size

            leftNumberInString = getLeftNumberInString squareNumberInString, sizeOfString
            rightNumberInString = getRightNumberInString squareNumberInString, sizeOfString

            potentialKaprekarNumber = sumNumbersInStrings leftNumberInString, rightNumberInString
        end

            def getLeftNumberInString squareNumberInString, sizeOfString
                digitsToSkip = 0
                digitsToTake = squareNumberInString.size - sizeOfString
                numberInString = squareNumberInString[digitsToSkip...digitsToTake]
            end

            def getRightNumberInString squareNumberInString, sizeOfString
                digitsToSkip = squareNumberInString.size - sizeOfString
                numberInString = squareNumberInString[digitsToSkip...]
            end

            def sumNumbersInStrings leftNumberInString, rightNumberInString
                if leftNumberInString.size > 0 && rightNumberInString.size > 0
                    return leftNumberInString.to_i + rightNumberInString.to_i
                elsif leftNumberInString.size == 0
                    return rightNumberInString.to_i
                elsif rightNumberInString.size == 0
                    return leftNumberInString.to_i
                end

                return 0
            end

    def printOutput array
        if array.size > 0
            puts array.join(' ')
        else
            puts "INVALID RANGE"
        end
    end

main
