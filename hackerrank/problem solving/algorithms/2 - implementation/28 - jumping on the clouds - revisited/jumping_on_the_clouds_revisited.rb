# https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

def main
  _, jump_length = read_numbers
  arr = read_numbers
  print(jumping_on_the_clouds(arr, jump_length))
end

def read_numbers
  gets.split.map(&:to_i)
end

def jumping_on_the_clouds(clouds, jump_length)
  energy = 100
  cloud_index = 0

  loop do
    energy -= clouds[cloud_index] == 0 ? 1 : 3
    cloud_index = (cloud_index + jump_length) % clouds.size
    break if cloud_index == 0
  end

  energy
end

main if __FILE__ == $PROGRAM_NAME
