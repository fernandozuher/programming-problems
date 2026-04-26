# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main
  gets
  socks_to_counts = read_numbers.tally
  puts sock_merchant(socks_to_counts)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# k: length of entries in socks_to_counts
# T: O(k)
# S: O(1) extra space
def sock_merchant(socks_to_counts)
  socks_to_counts.each_value.sum { _1 / 2 }
end

main if __FILE__ == $0
