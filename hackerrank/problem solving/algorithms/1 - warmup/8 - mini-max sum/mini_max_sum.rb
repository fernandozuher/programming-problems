# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

def main
  array = gets.split.map(&:to_i)
  array.sort!
  min_sum, max_sum = mini_max_sum(array)
  puts "#{min_sum} #{max_sum}"
end

  def mini_max_sum(array)
    total_sum = array.sum
    min_sum = total_sum - array.last
    max_sum = total_sum - array.first
    [min_sum, max_sum]
  end

main
