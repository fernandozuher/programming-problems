# https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

def main
  gets
  a = read_numbers
  b = read_numbers
  print(between_two_sets(a, b))
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

def between_two_sets(a, b)
  lcm_of_a = a.reduce(:lcm)
  gcd_of_b = b.reduce(:gcd)
  (lcm_of_a..gcd_of_b).step(lcm_of_a).count { |i| gcd_of_b % i == 0 }
end

main if __FILE__ == $0
