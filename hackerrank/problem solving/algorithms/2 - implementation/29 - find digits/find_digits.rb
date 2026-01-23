# https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main
  n = gets.to_i
  n.times do
    num = gets.to_i
    puts find_digits(num)
  end
end

# k: quantity of digits of num = log num
# 0 < num < 10^9
# T: O(k) = O(9) = O(1)
# S: O(k) = O(9) = O(1) extra space
def find_digits(num)
  num.to_s.each_char.map(&:to_i).count { |d| !d.zero? && (num % d).zero? }
end

main if __FILE__ == $0
