# https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

def main
  n = gets.to_i
  array = gets.split.map(&:to_i)
  p simple_array_sum(array)
end

  def simple_array_sum(array)
    array.sum
  end

main
