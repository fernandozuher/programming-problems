#!/bin/ruby

#
# Complete the 'compareTriplets' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def compareTriplets a, b
    player1, player2 = 0, 0

    a.zip(b).each do |number1, number2|
        if number1 > number2
            player1 += 1
        elsif number2 > number1
            player2 += 1
        end
    end
    [player1, player2]
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

a = gets.rstrip.split.map(&:to_i)

b = gets.rstrip.split.map(&:to_i)

result = compareTriplets a, b

fptr.write result.join " "
fptr.write "\n"

fptr.close()
