# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main
  _, k = read_numbers
  numbers = read_numbers
  puts divisible_sum_pairs(numbers, k)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of array numbers
# k: length of array frequency
# T: O(n + k)
# S: O(k) extra space
def divisible_sum_pairs(numbers, k)
  frequency = init_remainder_frequency(numbers, k)
  count_pairs_with_remainder_0(frequency) +
    count_complementary_remainder_pairs(frequency) +
    count_pairs_with_remainder_k_half(frequency)
end

def init_remainder_frequency(numbers, k)
  frequency = Array.new(k, 0)
  numbers.each { |x| frequency[x % k] += 1 }
  frequency
end

def count_pairs_with_remainder_0(frequency)
  pair_count(frequency[0])
end

def pair_count(n)
  n * (n - 1) / 2
end

def count_complementary_remainder_pairs(frequency)
  (1...(frequency.size + 1) / 2).sum { |i| frequency[i] * frequency[-i] }
end

def count_pairs_with_remainder_k_half(frequency)
  n = frequency.size
  n.even? ? pair_count(frequency[n / 2]) : 0
end

main if __FILE__ == $0
