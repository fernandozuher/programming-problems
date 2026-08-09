# https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

require 'morfo'

def main
  days = Morfo.read(&:to_i)
  puts viral_advertising(days)
end

# n: days
# T: O(n)
# S: O(1) extra space
def viral_advertising(days)
  shared = 5
  days.times.sum do
    liked = shared.div(2)
    shared = liked * 3
    liked
  end
end

main if __FILE__ == $0
