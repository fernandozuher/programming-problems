# Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main
    initialString = gets.strip
    finalString = gets.strip
    numberOfOperations = gets.to_i

    response = appendAndDelete initialString, finalString, numberOfOperations
    printOutput response
end

    def appendAndDelete initialString, finalString, numberOfOperations
        commonPrefixSizeBetweenStrings = findCommonPrefixSizeBetweenStrings initialString, finalString

        sizeOfDifferentCharactersFromInitialString = initialString.size - commonPrefixSizeBetweenStrings
        sizeOfDifferentCharactersFromFinalString = finalString.size - commonPrefixSizeBetweenStrings

        minimalQuantityOfOperationsToReplaceString = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromFinalString
        numberOfOperations -= minimalQuantityOfOperationsToReplaceString

        areOperationsSuitableToReplaceString numberOfOperations, commonPrefixSizeBetweenStrings
    end

        def findCommonPrefixSizeBetweenStrings initialString, finalString
            size = 0
            while size != initialString.size && size != finalString.size && initialString[size] == finalString[size]
                size += 1
            end
            size
        end

        def areOperationsSuitableToReplaceString numberOfOperations, commonPrefixSizeBetweenStrings
            if numberOfOperations < 0 ||
                (areOperationsBiggerThanZeroAndOdd(numberOfOperations) &&
                    areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations, commonPrefixSizeBetweenStrings))
                return false
            end
            return true
        end

            def areOperationsBiggerThanZeroAndOdd numberOfOperations
                numberOfOperations > 0 && numberOfOperations%2 == 1
            end

            def areNotOperationsEnoughToRemoveAndReplaceCommonPrefix numberOfOperations, commonPrefixSizeBetweenStrings
                numberOfOperations < commonPrefixSizeBetweenStrings*2
            end

    def printOutput response
        puts response ? "Yes" : "No"
    end

main
