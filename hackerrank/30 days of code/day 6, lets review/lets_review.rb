# https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

def main
  n = gets.to_i

  n.times {
    word = gets.chomp
    word1, word2 = '', ''
    is_word1_turn = true

    word.each_char { |ch|
      is_word1_turn ? (word1 += ch) : (word2 += ch)
      is_word1_turn = !is_word1_turn
    }

    puts "#{word1} #{word2}"
  }
end

main
