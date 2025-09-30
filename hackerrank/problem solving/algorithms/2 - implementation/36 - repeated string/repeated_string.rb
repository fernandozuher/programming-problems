# https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

def main
  string = gets.chomp
  n_characters = gets.to_i
  letter = 'a'
  puts count_in_repeated_string(string, letter, n_characters)
end

def count_in_repeated_string(string, letter, n_characters)
  full_repeats, n_substring = n_characters.divmod(string.size)
  substring = string[0...n_substring]

  quantity = string.count(letter)
  quantity *= full_repeats
  quantity + substring.count(letter)
end

main
