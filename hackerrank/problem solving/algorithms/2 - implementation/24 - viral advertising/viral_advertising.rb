# https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

def main
  days = gets.to_i
  puts viral_advertising(days)
end

# n = days = length of the iteration
# T = O(n)
# S = O(1)
def viral_advertising(days)
  shared = 5
  days.times.inject(0) do |cumulative, _|
    liked = shared.div(2)
    shared = liked * 3
    cumulative + liked
  end
end

main if __FILE__ == $PROGRAM_NAME
