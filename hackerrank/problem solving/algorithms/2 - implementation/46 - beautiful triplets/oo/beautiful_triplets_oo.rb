# Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

def main
    size, beautiful_difference = read_an_array
    array = read_an_array

    obj = BeautifulTriplets.new(array, beautiful_difference)
    puts obj.get_n_beautiful_triplets
end

    def read_an_array
        array = gets.split.map(&:to_i)
    end

    class BeautifulTriplets
        @array
        @beautiful_difference
        @n_beautiful_triplets

        def initialize(array, beautiful_difference)
            @array = array
            @beautiful_difference = beautiful_difference
            find_beautiful_triplets
        end

            private def find_beautiful_triplets
                @n_beautiful_triplets = 0

                if @array.size > 2
                    for i in 0...(@array.size-2)
                        for j in (i+1)...(@array.size-1)
                            first_difference = @array[j] - @array[i]

                            if first_difference < @beautiful_difference
                                next
                            elsif first_difference > @beautiful_difference
                                break
                            end
                            
                            for k in (j+1)...@array.size
                                second_difference = @array[k] - @array[j]

                                if second_difference == @beautiful_difference
                                    @n_beautiful_triplets += 1
                                elsif second_difference > @beautiful_difference
                                    break
                                end
                            end
                        end
                    end
                end
            end

        def get_n_beautiful_triplets
            @n_beautiful_triplets
        end
    end

main
