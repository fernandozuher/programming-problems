# https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true#!/bin/ruby

def main
    n = gets.to_i
    max_ones, ones = 0, 0

    while n > 0
        if n % 2 == 1
            ones += 1
        else
            max_ones = [max_ones, ones].max
            ones = 0
        end
        n /= 2
    end

    max_ones = [max_ones, ones].max
    puts max_ones
end

main
