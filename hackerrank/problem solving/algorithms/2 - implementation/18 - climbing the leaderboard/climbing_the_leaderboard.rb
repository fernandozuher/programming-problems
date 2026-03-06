# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

def main
  gets
  ranked = read_numbers
  ranked.uniq!
  gets
  player = read_numbers
  puts climbing_leaderboard(ranked, player)
end

def read_numbers
  gets.split.map!(&:to_i)
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
