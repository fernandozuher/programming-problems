# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main
  _, k = read_numbers
  numbers = read_numbers
  puts divisible_sum_pairs(numbers, k)
end

def read_numbers
  gets.split.map(&:to_i)
end

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
  k = frequency.size
  (1...(k + 1) / 2).sum { |i| frequency[i] * frequency[k - i] }
end

def count_pairs_with_remainder_k_half(frequency)
  k = frequency.size
  k.even? ? pair_count(frequency[k / 2]) : 0
end

main
