# https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true

def main
    n = gets.to_i
    for i in 1..10
        puts "#{n} x #{i} = #{n*i}"
    end
end

main
