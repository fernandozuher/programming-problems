# https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

def main
  gets
  puts sum_stdin
end

# n: number of integers in the input line
# T: O(n)
# S: O(n) extra space
def sum_stdin
  gets.split.map!(&:to_i).sum
end

main if __FILE__ == $0
