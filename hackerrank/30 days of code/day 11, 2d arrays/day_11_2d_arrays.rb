#!/bin/ruby

arr = Array.new(6)

6.times do |i|
    arr[i] = gets.rstrip.split.map(&:to_i)
end

maxSum = -9 * 7
for i in 1..4
    for j in 1..4

        currentSum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i][j] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1]

        if currentSum > maxSum
            maxSum = currentSum
        end
    end
end
puts maxSum