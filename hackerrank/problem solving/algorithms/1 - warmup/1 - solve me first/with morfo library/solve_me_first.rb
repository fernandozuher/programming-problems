# https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

require 'morfo'

def main
  n1 = Morfo.read(&:to_i)
  n2 = Morfo.read(&:to_i)
  puts solve_me_first(n1, n2)
end

# T: O(1)
# S: O(1) extra space
def solve_me_first(n1, n2) = n1 + n2

main if __FILE__ == $0
