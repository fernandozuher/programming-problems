# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

# n = test cases
# T = O(n)
# S = O(1)
def main
  n = gets.to_i
  n.times do
    prisoners, sweets, start_chair = read_numbers
    puts save_the_prisoner(prisoners, sweets, start_chair)
  end
end

# n = size of elements to be read
# T = O(n)
# S = O(n)
def read_numbers
  gets.split.map(&:to_i)
end

# T = O(1)
# S = O(1)
def save_the_prisoner(prisoners, sweets, start_chair)
  ((start_chair - 1 + sweets - 1) % prisoners) + 1
end

main if __FILE__ == $PROGRAM_NAME
