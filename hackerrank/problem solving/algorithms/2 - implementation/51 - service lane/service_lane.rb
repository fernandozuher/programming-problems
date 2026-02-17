# https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

def main
  _, t = read_numbers
  widths = read_numbers
  t.times { puts min_width_in_segment(widths, read_numbers) }
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of array widths
# T: O(n)
# S: O(1) extra space
def min_width_in_segment(widths, segment)
  start, finish = segment
  widths.lazy.drop(start).take(finish - start + 1).min
end

main if __FILE__ == $0
