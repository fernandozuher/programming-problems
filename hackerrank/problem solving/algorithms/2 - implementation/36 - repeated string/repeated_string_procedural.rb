# Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

def main
    inputString = gets.rstrip
    nCharacters = gets.to_i

    quantityOfA = findQuantityOfAInRepeatedString inputString, nCharacters
    puts quantityOfA
end

    def findQuantityOfAInRepeatedString inputString, nCharacters
        quantityOfA = findQuantityOfAInString inputString
        quantityOfA *= findQuantityOfRepeatedEntireString nCharacters, inputString.size
        quantityOfA += findQuantityOfRemainingA nCharacters, inputString

        quantityOfA
    end

        def findQuantityOfAInString inputString
            quantityOfA = 0

            for character in inputString.chars
                if character == 'a'
                    quantityOfA += 1
                end
            end

            quantityOfA
        end

        def findQuantityOfRepeatedEntireString nCharacters, sizeString
            nStrings = (nCharacters / sizeString).truncate
        end

        def findQuantityOfRemainingA nCharacters, inputString
            nRemainingCharactersOfString = nCharacters % inputString.size

            if nRemainingCharactersOfString == 0
                return 0
            end

            subString = inputString[0..(nRemainingCharactersOfString-1)]
            return findQuantityOfAInString subString
        end

main
