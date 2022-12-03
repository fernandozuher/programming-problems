#!/bin/ruby

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference arr
    primaryDiagonal, secondaryDiagonal = 0, 0
    
    j = arr.size - 1
    arr.each_index do |i|
        primaryDiagonal += arr.at(j).at(j)
        secondaryDiagonal += arr.at(j).at(i)
        j -= 1
    end
    (primaryDiagonal - secondaryDiagonal).abs
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.strip.to_i

arr = Array.new(n)

n.times do |i|
    arr[i] = gets.rstrip.split.map(&:to_i)
end

result = diagonalDifference arr

fptr.write result
fptr.write "\n"

fptr.close()
