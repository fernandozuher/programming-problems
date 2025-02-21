# https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

N = gets.to_i
array = gets.split.map(&:to_i)
puts array.reverse.join(' ')
