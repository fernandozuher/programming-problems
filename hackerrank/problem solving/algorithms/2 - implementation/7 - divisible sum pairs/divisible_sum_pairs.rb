# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main
  _, k = read_numbers
  numbers = read_numbers
  puts divisible_sum_pairs(numbers, k)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of numbers
# k: length of freq
# T: O(n + k)
# S: O(k) extra space
def divisible_sum_pairs(numbers, k)
  freq = init_remainder_frequency(numbers, k)
  count_pairs_with_remainder_0(freq) +
    count_complementary_remainder_pairs(freq) +
    count_pairs_with_remainder_k_half(freq)
end

def init_remainder_frequency(numbers, k)
  freq = Array.new(k, 0)
  numbers.each { freq[_1 % k] += 1 }
  freq
end

def count_pairs_with_remainder_0(freq)
  pair_count(freq.first)
end

def pair_count(n)
  n * (n - 1) / 2
end

def count_complementary_remainder_pairs(freq)
  (1...(freq.size + 1) / 2).sum { freq[_1] * freq[-_1] }
end

def count_pairs_with_remainder_k_half(freq)
  n = freq.size
  n.even? ? pair_count(freq[n / 2]) : 0
end

main if __FILE__ == $0
