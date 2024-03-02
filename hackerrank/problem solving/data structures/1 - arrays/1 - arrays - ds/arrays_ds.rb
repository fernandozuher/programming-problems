# https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

def main
    n = gets.to_i
    array = gets.split.map(&:to_i)
    array = reverse_array(array)
    puts array.join(' ')
end

    def reverse_array(array)
        array.reverse!
    end

main
