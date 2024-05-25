# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

def main
    n = gets.to_i
    array = gets.split.map(&:to_i)
    plus_minus(array)
end

    def plus_minus(array)
        positive, negative, zero = 0, 0, 0

        for number in array
            if number > 0
                positive += 1
            elsif number < 0
                negative += 1
            else
                zero += 1
            end
        end

        n = array.length.to_f
        positive_proportion = positive / n
        negative_proportion = negative / n
        zero_proportion = zero / n
        
        printf "%.6f\n", positive_proportion
        printf "%.6f\n", negative_proportion
        printf "%.6f\n", zero_proportion
    end

main
