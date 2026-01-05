# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main
  gets
  sock_counts = counter
  puts sock_merchant(sock_counts)
end

def counter
  gets&.split&.map!(&:to_i)&.tally
end

# n: quantity of entries in sock_counts
# T: O(n)
# S: O(1) extra space
def sock_merchant(sock_counts)
  sock_counts.each_value.sum { |count| count / 2 }
end

main if __FILE__ == $0
