# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main
  n = gets.to_i
  n.times do
    prisoners, sweets, start_chair = read_numbers
    puts save_the_prisoner(prisoners, sweets, start_chair)
  end
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# T: O(1)
# S: O(1) extra space
def save_the_prisoner(prisoners, sweets, start_chair)
  ((start_chair - 1 + sweets - 1) % prisoners) + 1
end

main if __FILE__ == $0
