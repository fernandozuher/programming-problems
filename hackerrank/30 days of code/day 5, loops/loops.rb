# https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true

n = gets.to_i
(1..10).each { |i|
  puts "#{n} x #{i} = #{n * i}"
}
