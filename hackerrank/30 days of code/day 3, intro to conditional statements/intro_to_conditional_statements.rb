# https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

n = gets.to_i

puts n & 1 == 1 || n >= 6 && n <= 20 ? "Weird" : "Not Weird"
