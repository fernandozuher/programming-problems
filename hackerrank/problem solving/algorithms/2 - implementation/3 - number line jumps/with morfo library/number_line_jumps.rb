# https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

require 'morfo'

def main
  initial_state = Morfo.read(4, &:to_i)
  puts kangaroo?(initial_state) ? "YES" : "NO"
end

# T: O(1)
# S: O(1) extra space
def kangaroo?(initial_state)
  x1, v1, x2, v2 = initial_state

  return x1 == x2 if v1 == v2

  distance_diff = x2 - x1
  velocity_diff = v1 - v2
  distance_diff * velocity_diff >= 0 && (distance_diff % velocity_diff).zero?
end

main if __FILE__ == $0
