#!/bin/ruby

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr)
    arr = arr.sort
    totalSum = arr.sum
    minSum = totalSum - arr[-1]
    maxSum = totalSum - arr[0]
    puts "#{minSum} #{maxSum}"
end

arr = gets.rstrip.split.map(&:to_i)
miniMaxSum arr
