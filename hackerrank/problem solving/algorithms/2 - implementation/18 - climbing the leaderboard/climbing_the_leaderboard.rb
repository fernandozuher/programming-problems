# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

def main
  gets
  ranked = read_numbers.uniq
  gets
  player = read_numbers
  puts climbing_leaderboard(ranked, player)
end

def read_numbers
  gets.split.map(&:to_i)
end

def climbing_leaderboard(ranked, player)
  i = ranked.length - 1
  player.map do |score|
    while i >= 0 && score >= ranked[i]
      i -= 1
    end
    i + 2
  end
end

main
