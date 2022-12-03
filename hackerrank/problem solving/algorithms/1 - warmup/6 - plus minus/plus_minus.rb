#!/bin/ruby

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus arr
    positiveQuantity, negativeQuantity, zeroQuantity = 0, 0, 0

    for number in arr
        if number > 0
            positiveQuantity += 1
        elsif number < 0
            negativeQuantity += 1
        else
            zeroQuantity += 1
        end
    end

    n = arr.length.to_f
    positiveValuesProportion = positiveQuantity / n
    negativeValuesProportion = negativeQuantity / n
    zeroValuesProportion = zeroQuantity / n
    
    printf "%.6f\n", positiveValuesProportion
    printf "%.6f\n", negativeValuesProportion
    printf "%.6f\n", zeroValuesProportion
end

n = gets.strip.to_i
arr = gets.rstrip.split.map(&:to_i)
plusMinus arr
