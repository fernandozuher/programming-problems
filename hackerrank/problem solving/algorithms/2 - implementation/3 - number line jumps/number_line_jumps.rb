# https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

def main
  initial_state = read_numbers
  puts kangaroo(initial_state) ? "YES" : "NO"
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# T: O(1)
# S: O(1) extra space
def kangaroo(initial_state)
  x1, v1, x2, v2 = initial_state

  return x1 == x2 if v1 == v2

  distance_diff = x2 - x1
  velocity_diff = v1 - v2
  distance_diff * velocity_diff >= 0 && distance_diff % velocity_diff == 0
end

main if __FILE__ == $0
