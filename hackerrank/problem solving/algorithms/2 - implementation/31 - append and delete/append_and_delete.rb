# https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main
  initial_string = gets.strip
  final_string = gets.strip
  n_operations = gets.to_i
  puts append_and_delete?(initial_string, final_string, n_operations) ? 'Yes' : 'No'
end

def append_and_delete?(s1, s2, n_ops)
  prefix_len = common_prefix_length(s1, s2)
  needed_ops = (s1.length - prefix_len) + (s2.length - prefix_len)
  can_remove_all = n_ops >= s1.length + s2.length
  can_remove_all || (n_ops >= needed_ops && (n_ops - needed_ops).even?)
end

def common_prefix_length(s1, s2)
  min_len = [s1.length, s2.length].min
  min_len.times do |i|
    return i if s1[i] != s2[i]
  end
  min_len
end

main if __FILE__ == $PROGRAM_NAME
