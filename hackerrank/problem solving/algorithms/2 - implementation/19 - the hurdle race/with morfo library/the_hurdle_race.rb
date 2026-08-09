# https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input
  max_jump = Morfo.read(&:to_i)
  hurdles = Morfo.readln(&:to_i)
  puts hurdle_race(hurdles, max_jump)
end

# n: length of hurdles
# T: O(n)
# S: O(1) extra space
def hurdle_race(hurdles, max_jump) = [0, hurdles.max - max_jump].max

main if __FILE__ == $0
