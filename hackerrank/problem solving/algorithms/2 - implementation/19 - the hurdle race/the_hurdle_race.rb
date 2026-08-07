# https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

def main
  _, max_jump = read_nums
  hurdles = read_nums
  puts hurdle_race(hurdles, max_jump)
end

def read_nums = gets.split.map!(&:to_i)

# n: length of hurdles
# T: O(n)
# S: O(1) extra space
def hurdle_race(hurdles, max_jump) = [0, hurdles.max - max_jump].max

main if __FILE__ == $0
