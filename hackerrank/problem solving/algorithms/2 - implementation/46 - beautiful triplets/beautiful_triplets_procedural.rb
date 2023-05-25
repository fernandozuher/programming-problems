# Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

def main
    size, beautiful_difference = read_an_array
    array = read_an_array

    n_beautiful_triplets = find_beautiful_triplets(array, beautiful_difference)
    puts n_beautiful_triplets
end

    def read_an_array
        array = gets.split.map(&:to_i)
    end

    def find_beautiful_triplets(array, beautiful_difference)
        n_beautiful_triplets = 0

        if array.size > 2
            for i in 0...(array.size-2)
                for j in (i+1)...(array.size-1)
                    first_difference = array[j] - array[i]

                    if first_difference < beautiful_difference
                        next
                    elsif first_difference > beautiful_difference
                        break
                    end
                    
                    for k in (j+1)...array.size
                        second_difference = array[k] - array[j]

                        if second_difference == beautiful_difference
                            n_beautiful_triplets += 1
                        elsif second_difference > beautiful_difference
                            break
                        end
                    end
                end
            end
        end

        n_beautiful_triplets
    end

main
