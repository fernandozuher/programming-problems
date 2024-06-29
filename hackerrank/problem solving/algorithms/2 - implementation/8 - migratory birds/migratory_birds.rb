# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

def main
  _n = gets.to_i
  array = read_int_array
  array.sort!
  p find_most_spotted_bird(array)
end

  def read_int_array
    gets.split.map(&:to_i)
  end

  def find_most_spotted_bird(bird_sightings)
    most_spotted_bird = bird_sightings.first
    count_most_spotted_bird = 1
    temp_count_most_spotted_bird = 1

    bird_sightings.each_cons(2) { |current_bird, next_bird|
      if current_bird == next_bird
        temp_count_most_spotted_bird += 1
      elsif temp_count_most_spotted_bird > count_most_spotted_bird
        most_spotted_bird = current_bird
        count_most_spotted_bird = temp_count_most_spotted_bird
        temp_count_most_spotted_bird = 1
      end
    }

    if temp_count_most_spotted_bird > count_most_spotted_bird
      most_spotted_bird = bird_sightings.last
    end

    most_spotted_bird
  end

main
