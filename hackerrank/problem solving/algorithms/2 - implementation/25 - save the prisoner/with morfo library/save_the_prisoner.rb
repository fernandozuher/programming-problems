# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  n.times do
    prisoners, sweets, start_chair = Morfo.read(3, &:to_i)
    puts save_the_prisoner(prisoners, sweets, start_chair)
  end
end

# T: O(1)
# S: O(1) extra space
def save_the_prisoner(prisoners, sweets, start_chair) = ((start_chair - 1 + sweets - 1) % prisoners) + 1

main if __FILE__ == $0
