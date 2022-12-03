#!/bin/ruby

#
# Complete the 'bitwiseAnd' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER N
#  2. INTEGER K
#

def bitwiseAnd(n, k)
    maximumValueLessThanK = 0
    for i in 1..n
        for j in i+1..n
            operation = i & j
            if operation < k and operation > maximumValueLessThanK
                if operation == k-1
                    return operation
                else
                    maximumValueLessThanK = operation
                end
            end 
        end
    end
    maximumValueLessThanK
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

t = gets.strip.to_i

t.times do
    first_multiple_input = gets.rstrip.split
    count = first_multiple_input[0].to_i
    lim = first_multiple_input[1].to_i

    res = bitwiseAnd count, lim
    fptr.write res
    fptr.write "\n"
end

fptr.close()
