# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main
  gets
  sock_counts = read_numbers_into_map
  puts sock_merchant(sock_counts)
end

def read_numbers_into_map
  gets.split.map(&:to_i).tally
end

def sock_merchant(sock_counts)
  sock_counts.values.sum { |count| count / 2 }
end

main
