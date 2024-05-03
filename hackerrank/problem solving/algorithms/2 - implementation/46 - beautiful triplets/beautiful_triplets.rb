# https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

def main
  _, beautiful_difference = read_int_array
  array = read_int_array
  p find_beautiful_triplets(array, beautiful_difference)
end

  def read_int_array
    gets.split.map(&:to_i)
  end
  
  def find_beautiful_triplets(array, beautiful_difference)
    n_beautiful_triplets = 0

    if array.size > 2
      array[0...-2].each_with_index do |v1, i|
        array[i + 1...-1].each_with_index do |v2, j|
          if (first_difference = v2 - v1) < beautiful_difference
            next
          elsif first_difference > beautiful_difference
            break
          end

          j += i + 1
          array[j + 1..].each do |v3|
            if (second_difference = v3 - v2) == beautiful_difference
              n_beautiful_triplets += 1
            elsif second_difference > beautiful_difference
              break
            end
          end
        end
      end
    end

    n_beautiful_triplets
  end

main
