# https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

def main
  n = gets.to_i
  staircase(n)
end

# T: O(n^2)
# S: O(n) extra space
def staircase(n)
  n.times do
    hashes = '#' * (_1 + 1)
    puts hashes.rjust(n)
  end
end

main if __FILE__ == $0
