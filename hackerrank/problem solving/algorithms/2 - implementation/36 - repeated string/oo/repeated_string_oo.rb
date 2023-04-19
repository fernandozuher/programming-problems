# Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

def main
    inputString = gets.rstrip
    nCharacters = gets.to_i

    obj = RepeatedString.new inputString, nCharacters
    quantityOfA = obj.getQuantityOfA
    puts quantityOfA
end

    class RepeatedString
        @inputString
        @nCharacters
        @quantityOfA

        def initialize inputString, nCharacters
            @inputString = inputString
            @nCharacters = nCharacters
            @quantityOfA = 0

            _findQuantityOfAInRepeatedString
        end

            def _findQuantityOfAInRepeatedString
                @quantityOfA = _findQuantityOfAInString @inputString
                @quantityOfA *= _findQuantityOfRepeatedEntireString
                @quantityOfA += _findQuantityOfRemainingA
            end

                def _findQuantityOfAInString inputString
                    quantityOfA = 0

                    for character in inputString.chars
                        if character == 'a'
                            quantityOfA += 1
                        end
                    end

                    quantityOfA
                end

                def _findQuantityOfRepeatedEntireString
                    nStrings = (@nCharacters / @inputString.size).truncate
                end

                def _findQuantityOfRemainingA
                    nRemainingCharactersOfString = @nCharacters % @inputString.size

                    if nRemainingCharactersOfString == 0
                        return 0
                    end

                    subString = @inputString[0..(nRemainingCharactersOfString-1)]
                    return _findQuantityOfAInString subString
                end

        def getQuantityOfA
            @quantityOfA
        end
    end

main
