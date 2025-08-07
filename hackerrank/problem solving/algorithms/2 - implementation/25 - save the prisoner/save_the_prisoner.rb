# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main
  n = gets.to_i
  (0...n).map do
    prisoners, sweets, start_chair = read_numbers
    save_the_prisoner(prisoners, sweets, start_chair)
  end.each { |x| puts x }
end

def read_numbers
  gets.split.map(&:to_i)
end

def save_the_prisoner(prisoners, sweets, start_chair)
  ((start_chair - 1 + sweets - 1) % prisoners) + 1
end

main if __FILE__ == $PROGRAM_NAME
