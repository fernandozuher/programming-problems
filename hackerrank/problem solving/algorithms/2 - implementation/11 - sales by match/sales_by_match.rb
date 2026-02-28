# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main
  gets
  socks_to_counts = counter
  puts sock_merchant(socks_to_counts)
end

# n: length of user input
# k: length of distinct numbers in user input
# T: O(n)
# S: O(n) extra space
def counter
  gets.split.map!(&:to_i).tally
end

# n: length of initial user input
# k: length of entries in socks_to_counts
# k <= n
# T: O(k)
# S: O(1) extra space
def sock_merchant(socks_to_counts)
  socks_to_counts.each_value.sum { _1 / 2 }
end

main if __FILE__ == $0
