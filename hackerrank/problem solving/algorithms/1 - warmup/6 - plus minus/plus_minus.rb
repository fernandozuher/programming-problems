# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

def main
    n = gets.to_i
    array = gets.split.map(&:to_i)
    plus_minus(array)
end

    def plus_minus(array)
        positive_quantity, negative_quantity, zero_quantity = 0, 0, 0

        for number in array
            if number > 0
                positive_quantity += 1
            elsif number < 0
                negative_quantity += 1
            else
                zero_quantity += 1
            end
        end

        n = array.length.to_f
        positive_values_proportion = positive_quantity / n
        negative_values_proportion = negative_quantity / n
        zero_values_proportion = zero_quantity / n
        
        printf "%.6f\n", positive_values_proportion
        printf "%.6f\n", negative_values_proportion
        printf "%.6f\n", zero_values_proportion
    end

main
