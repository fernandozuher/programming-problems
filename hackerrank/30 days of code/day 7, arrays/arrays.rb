# https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

def main
    _n = gets.to_i
    array = gets.split.map(&:to_i)
    array.reverse_each { |element| print element, " " }
end

main
