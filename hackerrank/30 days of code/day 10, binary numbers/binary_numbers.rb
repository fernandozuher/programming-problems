# https://www.hackerrank.com/challenges/30-binary-numbers/problem?is_full_screen=true

def main
  n = gets.to_i
  binary = n.to_s(2)
  print max_consecutive_ones_from(binary)
end

def max_consecutive_ones_from(binary)
  max_1_bits = 0
  i = 0
  while i < binary.size
    if binary[i] == '1'
      n_bits = size_of_next_range_of_bits_1(binary, i)
      max_1_bits = [n_bits, max_1_bits].max
      i += n_bits
    end
    i += 1
  end
  max_1_bits
end

def size_of_next_range_of_bits_1(binary, begin_index)
  next_after_last_index = find_next_after_last_index_of_consecutive_1s(binary, begin_index)
  next_after_last_index - begin_index
end

def find_next_after_last_index_of_consecutive_1s(binary, begin_index)
  next_after_last_index = binary.index('0', begin_index)
  next_after_last_index == nil ? binary.size : next_after_last_index
end

main
