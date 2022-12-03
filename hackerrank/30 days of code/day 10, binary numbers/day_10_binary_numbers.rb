#!/bin/ruby

n = gets.strip.to_i
max_ones, ones = 0, 0

while n > 0
    if n % 2 == 1
        ones += 1
    else
        if ones > max_ones
            max_ones = ones
        end
        ones = 0
    end
    n /= 2
end

puts ones > max_ones ? ones : max_ones