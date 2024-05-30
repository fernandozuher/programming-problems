# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

def main
  _n = gets.to_i
  array = gets.split.map(&:to_i)
  positive_proportion, negative_proportion, zero_proportion = plus_minus(array)
  printf "%.6f\n", positive_proportion
  printf "%.6f\n", negative_proportion
  printf "%.6f\n", zero_proportion
end

  def plus_minus(array)
    positive, negative, zero = 0, 0, 0
  
    array.each { |x|
      if x > 0
        positive += 1
      elsif x < 0
        negative += 1
      else
        zero += 1
      end
    }
  
    n = array.length.to_f
    positive_proportion = positive / n
    negative_proportion = negative / n
    zero_proportion = zero / n
  
    [positive_proportion, negative_proportion, zero_proportion]
  end

main
