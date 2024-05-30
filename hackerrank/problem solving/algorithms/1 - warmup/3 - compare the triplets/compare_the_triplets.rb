# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

def main
  array1 = read_int_array
  array2 = read_int_array
  player1, player2 = compare_triplets(array1, array2)
  puts "#{player1} #{player2}"
end

  def read_int_array
    gets.split.map(&:to_i)
  end

  def compare_triplets(array1, array2)
    player1, player2 = 0, 0

    array1.zip(array2).each do |p1, p2|
      if p1 > p2
        player1 += 1
      elsif p2 > p1
        player2 += 1
      end
    end

    [player1, player2]
  end

main
