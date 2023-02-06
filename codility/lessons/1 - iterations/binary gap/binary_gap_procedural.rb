# Source: https://app.codility.com/programmers/lessons/1-iterations/binaryGap/

def solution number
    binary = convertNumberToBinaryString number
    longestBinaryGap = findLongestBinaryGap binary
end

    def convertNumberToBinaryString number
        binary = number.to_s(2)
    end

    def findLongestBinaryGap binary
        longestBinaryGap = 0
        index = {"i" => 0, "j" => 0, "k" => 0}

        while index.has_value?(nil) == false do
            gapLength = findGapLength binary, index
            longestBinaryGap = [gapLength, longestBinaryGap].max
        end
        
        longestBinaryGap
    end

        def findGapLength binary, index
            index['i'] = binary.index('1', index['j'])

            if index['i'] != nil
                index['j'] = binary.index('0', index['i'] + 1)

                if index['j'] != nil
                    index['k'] = binary.index('1', index['j'] + 1)

                    if index['k'] != nil
                        gap_length = index['k'] - index['j']
                    else
                        0
                    end
                else
                    0
                end
            else
                0
            end
        end
