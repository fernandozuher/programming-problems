# https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

n = gets.to_i
is_weird = n & 1 == 1 || n >= 6 && n <= 20
puts is_weird ? "Weird" : "Not Weird"
