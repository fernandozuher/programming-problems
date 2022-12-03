#!/bin/ruby

#
# Complete the 'staircase' function below.
#
# The function accepts INTEGER n as parameter.
#

def staircase(n)
    for i in 1..n
        (0..n-i-1).each do
            print " "
        end
        (0..i-1).each do
            print "#"
        end
        puts ""
    end
end

n = gets.strip.to_i
staircase n
