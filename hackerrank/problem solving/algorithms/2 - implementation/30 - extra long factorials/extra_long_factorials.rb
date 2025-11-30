# https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

def main
  n = gets.to_i
  puts factorial(n)
end

def factorial(n)
  (1..n).reduce(:*)
end

main if __FILE__ == $PROGRAM_NAME
