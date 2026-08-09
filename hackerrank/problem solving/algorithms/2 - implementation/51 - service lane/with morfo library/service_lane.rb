# https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

require 'morfo'

def main
  _, t = Morfo.readln(&:to_i)
  widths = Morfo.readln(&:to_i)
  t.times { puts min_width_in_segment(widths, Morfo.readln(&:to_i)) }
end

# n: length of widths
# T: O(n)
# S: O(1) extra space
def min_width_in_segment(widths, segment)
  start, finish = segment
  widths.lazy.drop(start).take(finish - start + 1).min
end

main if __FILE__ == $0
