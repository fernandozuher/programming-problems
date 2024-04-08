# https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

def main
    string = gets.chomp
    n_characters = gets.to_i
    letter = 'a'
    puts count_in_repeated_string(string, letter, n_characters)
end

    def count_in_repeated_string(string, letter, n_characters)
        repeated_entire_string, n_substring = n_characters.divmod(string.size)
        substring = string[0...n_substring]

        quantity = string.count(letter)
        quantity *= repeated_entire_string
        quantity += substring.count(letter)
    end

main
