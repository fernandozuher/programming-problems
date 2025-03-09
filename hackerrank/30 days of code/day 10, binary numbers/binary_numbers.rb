# https://www.hackerrank.com/challenges/30-binary-numbers/problem?is_full_screen=true

def main
  n = gets.to_i
  binary = n.to_s(2)
  puts find_max_length_of_ones(binary)
end

def find_max_length_of_ones(binary)
  binary.split('0').map(&:length).max
end

main
