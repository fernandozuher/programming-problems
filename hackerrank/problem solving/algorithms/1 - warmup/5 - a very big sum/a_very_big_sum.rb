# https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

def main
  _ = gets.to_i
  array = gets.split.map(&:to_i)
  p a_very_big_sum(array)
end

  def a_very_big_sum(array)
    array.sum
  end

main
