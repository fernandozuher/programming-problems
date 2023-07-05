# Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

def solution(number)
    obj = BinaryGap.new(number)
    obj.get_longest_binary_gap 
end

    class BinaryGap
        @number
        @binary
        @longest_binary_gap

        def initialize(number)
            @number = number
            @binary = ""
            @longest_binary_gap = 0

            @binary = convert_number_to_binary_string(@number)
            find_longest_binary_gap
        end

            private def convert_number_to_binary_string(n)
                n.to_s(2)
            end

            private def find_longest_binary_gap
                index = {"i" => 0, "j" => 0, "k" => 0}

                while index.has_value?(nil) == false do
                    gap_length = find_gap_length(index)
                    @longest_binary_gap = [gap_length, @longest_binary_gap].max
                end
            end

                private def find_gap_length(index)
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

        def get_longest_binary_gap
            @longest_binary_gap
        end
    end
