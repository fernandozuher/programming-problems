# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  ranked = Morfo.readln(&:to_i)
  ranked.uniq!
  Morfo.skip_input_ln
  player = Morfo.readln(&:to_i)
  puts climbing_leaderboard(ranked, player)
end

# n1: length of player, output
# n2: length of ranked
# T: O(n1 + n2)
# S: O(n1) extra space
def climbing_leaderboard(ranked, player)
  i = ranked.length - 1
  player.map do |score|
    i -= 1 while i >= 0 && score >= ranked[i]
    i + 2
  end
end

main if __FILE__ == $0
