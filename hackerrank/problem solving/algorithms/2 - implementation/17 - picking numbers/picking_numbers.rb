# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

def main
  gets
  puts picking_numbers(counter)
end

def counter
  gets&.split&.map!(&:to_i)&.tally
end

# n: length of initial input array of numbers
# k: length of map frequency
# T:
#   Without constraining the input values:
#       In the worst case, length of map equals length of initial input array when there is no repeated element: k = n
#       O(n)
#   With input values limited to 1 through 99, as stated in the problem:
#       Max of 99 keys/values at map: O(99) = O(1)
# S: O(1) extra space
def picking_numbers(frequency)
  frequency.each_key.inject(0) do |max_len, num|
    [max_len, frequency[num] + frequency.fetch(num + 1, 0)].max
  end
end

main if __FILE__ == $0
