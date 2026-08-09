# https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  arr = Morfo.readln(&:to_i)
  puts min_distance(arr)
end

# n: length of arr
# T: O(n)
# S: O(n) extra space
def min_distance(arr)
  last_seen = {}
  min_dist = -1

  arr.each_with_index do |x, i|
    if last_seen.key?(x)
      dist = i - last_seen[x]

      if min_dist == -1 or dist < min_dist
        min_dist = dist
        return 1 if min_dist == 1
      end
    end

    last_seen[x] = i
  end

  min_dist
end

main if __FILE__ == $0
