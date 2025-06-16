# https://www.hackerrank.com/challenges/between-two-sets/problem?is_full_screen=true

def main
  gets
  numbers_a = read_numbers
  numbers_b = read_numbers
  print(between_two_sets(numbers_a, numbers_b))
end

def read_numbers
  gets.split.map(&:to_i)
end

def between_two_sets(a, b)
  lcm_of_a = lcm_array(a)
  gcd_of_b = gcd_array(b)

  (lcm_of_a..gcd_of_b).step(lcm_of_a).filter do |i|
    gcd_of_b % i == 0
  end.count
end

def lcm_array(numbers)
  numbers[1..].reduce(numbers[0], :lcm)
end

def gcd_array(numbers)
  numbers[1..].reduce(numbers[0], :gcd)
end

main
