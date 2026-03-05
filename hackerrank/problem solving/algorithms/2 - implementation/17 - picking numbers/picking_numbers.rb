# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

def main
  gets
  puts picking_numbers(counter)
end

# n: length of initial input array of numbers
# T: O(n)
# S: O(n) extra space
def counter
  gets.split.map!(&:to_i).tally
end

# k: length of freq_map
# 1 <= k <= 99
# T: O(k) = O(99) = O(1)
# S: O(1) extra space
def picking_numbers(freq_map)
  freq_map.each_key.inject(0) do |max_len, num|
    [max_len, freq_map[num] + freq_map.fetch(num + 1, 0)].max
  end
end

main if __FILE__ == $0
