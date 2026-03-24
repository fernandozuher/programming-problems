# https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

def main
  str = gets.chomp
  n_chars = gets.to_i
  letter = 'a'
  puts count_in_repeated_string(str, letter, n_chars)
end

# n: length of str
# T: O(n)
# S: O(1) extra space
def count_in_repeated_string(str, letter, n_chars)
  full_repeats, n_substr = n_chars.divmod(str.size)

  count = str.count(letter)
  count *= full_repeats
  substr_count = (0...n_substr).count { str[_1] == letter }
  count + substr_count
end

main if __FILE__ == $0
