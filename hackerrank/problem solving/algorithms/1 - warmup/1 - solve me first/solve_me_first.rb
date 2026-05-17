# https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

def main
  n1 = gets.to_i
  n2 = gets.to_i
  puts solve_me_first(n1, n2)
end

# T: O(1)
# S: O(1) extra space
def solve_me_first(n1, n2)
  n1 + n2
end

main if __FILE__ == $0
