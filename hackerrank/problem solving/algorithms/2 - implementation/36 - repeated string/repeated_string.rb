# https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

def main
  string = gets.chomp
  n_characters = gets.to_i
  letter = 'a'
  puts count_in_repeated_string(string, letter, n_characters)
end

# n: length of string
# T: O(n)
# S: O(1) extra space
def count_in_repeated_string(string, letter, n_characters)
  full_repeats, n_substring = n_characters.divmod(string.size)

  count = string.count(letter)
  count *= full_repeats
  substring_count = (0...n_substring).count { |i| string[i] == letter }
  count + substring_count
end

main if __FILE__ == $0
