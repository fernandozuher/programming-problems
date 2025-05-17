# https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

def main
  gets
  puts sum_stdin
end

def sum_stdin
  gets.split.map(&:to_i).sum
end

main
