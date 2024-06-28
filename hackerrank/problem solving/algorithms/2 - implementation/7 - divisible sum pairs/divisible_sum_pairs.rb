# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main
  _, k = read_int_array
  array = read_int_array
  array.sort!
  p divisible_sum_pairs(array, k)
end

  def read_int_array
    gets.split.map(&:to_i)
  end
  
  def divisible_sum_pairs(array, k)
    n_divisible_sum_pairs = 0
  
    array[...-1].each_with_index { |num1, i|
      array[i + 1...].each { |num2|
        if num1 <= num2 and (num1 + num2) % k == 0
          n_divisible_sum_pairs += 1;
        end
      }
    }
  
    n_divisible_sum_pairs
  end

main
