# https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main
  s1 = gets&.strip
  s2 = gets&.strip
  n_ops = gets.to_i
  puts append_and_delete?(s1, s2, n_ops) ? 'Yes' : 'No'
end

# n1: length of string s1
# n2: length of string s2
# T: O(min(n1, n2))
# S: O(1) extra space
def append_and_delete?(s1, s2, n_ops)
  prefix_len = common_prefix_length(s1, s2)
  ops_needed = (s1.size - prefix_len) + (s2.size - prefix_len)
  return false if n_ops < ops_needed
  return true if n_ops >= s1.size + s2.size
  (n_ops - ops_needed).even?
end

def common_prefix_length(s1, s2)
  min_len = [s1.size, s2.size].min
  min_len.times { |i| return i if s1[i] != s2[i] }
  min_len
end

main if __FILE__ == $0
