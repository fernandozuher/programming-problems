# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  socks_to_counts = Morfo.readln(&:to_i).tally
  puts sock_merchant(socks_to_counts)
end

# k: length of entries in socks_to_counts
# T: O(k)
# S: O(1) extra space
def sock_merchant(socks_to_counts) = socks_to_counts.each_value.sum { _1 / 2 }

main if __FILE__ == $0
