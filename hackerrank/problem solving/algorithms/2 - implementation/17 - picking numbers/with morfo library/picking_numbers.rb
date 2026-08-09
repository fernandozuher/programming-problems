# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  freq_map = Morfo.readln(&:to_i).tally
  puts picking_numbers(freq_map)
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
