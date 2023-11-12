# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

def main
    array1 = read_an_int_array
    array2 = read_an_int_array
    result = compare_triplets(array1, array2)
    puts "#{result[0]} #{result[1]}"
end

    def read_an_int_array
        gets.split.map(&:to_i)
    end

    def compare_triplets(array1, array2)
        player1, player2 = 0, 0

        array1.zip(array2).each do |val1, val2|
            if val1 > val2
                player1 += 1
            elsif val2 > val1
                player2 += 1
            end
        end

        [player1, player2]
    end

main
