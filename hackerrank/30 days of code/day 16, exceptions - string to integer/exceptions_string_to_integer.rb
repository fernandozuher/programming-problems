# https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

s = gets.chomp
puts Integer(s) rescue puts "Bad String"
