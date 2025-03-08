# https://www.hackerrank.com/challenges/30-binary-numbers/problem?is_full_screen=true

def main
  n = gets.to_i
  binary = int_to_binary(n)
  puts find_size_widest_range_bits_1_from(binary)
end

def int_to_binary(n)
  n.to_s(2)
end

def find_size_widest_range_bits_1_from(binary)
  size_widest_range = 0
  i = 0
  while i < binary.size
    if binary[i] == '1'
      binary_from_i = binary[i..]
      size_range = find_size_next_range_bits_1_from(binary_from_i)
      size_widest_range = [size_range, size_widest_range].max
      i += size_range
    end
    i += 1
  end
  size_widest_range
end

def find_size_next_range_bits_1_from(binary)
  binary.index('0') || binary.size
end

main
