# Source: https://app.codility.com/programmers/lessons/1-iterations/binaryGap/

def solution(number)
    iterations = Iterations.new number
    longestBinaryGap = iterations.getLongestBinaryGap
end

    class Iterations

        @binary
        @longestBinaryGap

        def initialize number
            @binary = _convertNumberToBinaryString number
            @longestBinaryGap = _findLongestBinaryGap
        end

            def _convertNumberToBinaryString n
                binary = n.to_s(2)
            end

            def _findLongestBinaryGap
                longestBinaryGap = 0
                index = {"i" => 0, "j" => 0, "k" => 0}

                while index.has_value?(nil) == false do
                    gapLength = _findGapLength index
                    longestBinaryGap = [gapLength, longestBinaryGap].max
                end

                longestBinaryGap
            end

                def _findGapLength index
                    index['i'] = @binary.index('1', index['j'])

                    if index['i'] != nil
                        index['j'] = @binary.index('0', index['i'] + 1)

                        if index['j'] != nil
                            index['k'] = @binary.index('1', index['j'] + 1)

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

        def getLongestBinaryGap
            @longestBinaryGap
        end
    end
