# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

def main
    array = gets.split.map(&:to_i)
    array.sort!
    mini_max_sum(array)
end

    def mini_max_sum(array)
        total_sum = array.sum
        min_sum = total_sum - array[-1]
        max_sum = total_sum - array[0]
        puts "#{min_sum} #{max_sum}"
    end

main
