# https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

def main
  n = gets.to_i
  puts factorial(n)
end

# T: O(n)
# S: O(1) extra space (excluding the size of the resulting integer)
def factorial(n)
  (1..n).reduce(:*)
end

main if __FILE__ == $0
