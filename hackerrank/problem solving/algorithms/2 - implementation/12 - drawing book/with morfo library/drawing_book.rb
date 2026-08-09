# https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  page = Morfo.read(&:to_i)
  puts count_page(n, page)
end

# T: O(1)
# S: O(1) extra space
def count_page(n, page)
  from_front = page / 2
  from_back = n / 2 - from_front
  [from_front, from_back].min
end

main if __FILE__ == $0
