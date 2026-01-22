# https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

def main
  _, jump_length = read_numbers
  arr = read_numbers
  print(jumping_on_the_clouds(arr, jump_length))
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# n: length of array clouds; 2 to 25
# k (jump_length): 1 <= k <= n
# n % k = 0
# c[i] = 0 or 1
# T: O(n) = O(25) = O(1)
# S: O(1) extra space
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

main if __FILE__ == $0
