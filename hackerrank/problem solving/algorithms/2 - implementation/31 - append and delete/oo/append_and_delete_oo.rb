#Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main
    initialString = gets.strip
    finalString = gets.strip
    numberOfOperations = gets.to_i

    obj = AppendAndDelete.new initialString, finalString, numberOfOperations
    response = obj.getResponse
    printOutput response
end

    def printOutput response
        puts response ? "Yes" : "No"
    end

    class AppendAndDelete
        @initialString
        @finalString
        @numberOfOperations

        @commonPrefixSizeBetweenStrings
        @areOperationsSuitableToReplacement

        def initialize initialString, finalString, numberOfOperations
            @initialString = initialString
            @finalString = finalString
            @numberOfOperations = numberOfOperations

            _appendAndDelete
        end

            private def _appendAndDelete
                @commonPrefixSizeBetweenStrings = _findCommonPrefixSizeBetweenStrings

                sizeOfDifferentCharactersFromInitialString = @initialString.size - @commonPrefixSizeBetweenStrings
                sizeOfDifferentCharactersFromFinalString = @finalString.size - @commonPrefixSizeBetweenStrings

                minimalQuantityOfOperationsToReplaceString = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromFinalString
                
                @numberOfOperations -= minimalQuantityOfOperationsToReplaceString
                @areOperationsSuitableToReplacement = _areOperationsSuitableToReplaceString
            end

                private def _findCommonPrefixSizeBetweenStrings
                    size = 0
                    while size != @initialString.size && size != @finalString.size && @initialString[size] == @finalString[size]
                        size += 1
                    end
                    size
                end

                private def _areOperationsSuitableToReplaceString
                    if @numberOfOperations < 0 ||
                        (_areOperationsBiggerThanZeroAndOdd && _areNotOperationsEnoughToRemoveAndReplaceCommonPrefix)
                        return false
                    end
                    return true
                end

                    private def _areOperationsBiggerThanZeroAndOdd
                        @numberOfOperations > 0 && @numberOfOperations%2 == 1
                    end

                    private def _areNotOperationsEnoughToRemoveAndReplaceCommonPrefix
                        @numberOfOperations < @commonPrefixSizeBetweenStrings*2
                    end

        def getResponse
            @areOperationsSuitableToReplacement
        end
    end
    
main
