# https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

def main
  n = gets.to_i
  p diagonal_difference(n)
end

  def diagonal_difference(n)
    primary_diagonal, secondary_diagonal = 0, 0
    j = n - 1
  
    n.times do |i|
      line = gets.split.map(&:to_i)
      primary_diagonal += line[i]
      secondary_diagonal += line[j]
      j -= 1
    end
  
    (primary_diagonal - secondary_diagonal).abs
  end

main
