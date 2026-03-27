# https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

def main
  gets
  a = read_numbers
  b = read_numbers
  print(between_two_sets(a, b))
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n1, n2: length of a, b
# k: number of multiples tested = gcd_of_b / lcm_of_a
# T: O(n1 + n2 + k)
# S: O(1) extra space
def between_two_sets(a, b)
  lcm_of_a = a.reduce(:lcm)
  gcd_of_b = b.reduce(:gcd)
  (lcm_of_a..gcd_of_b).step(lcm_of_a).count { (gcd_of_b % _1).zero? }
end

main if __FILE__ == $0
