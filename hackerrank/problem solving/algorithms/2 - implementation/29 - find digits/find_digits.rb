# https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main
  n = gets.to_i
  n.times { puts find_digits(gets.to_i) }
end

def find_digits(n)
  n.to_s.chars.map(&:to_i).count { |d| d != 0 && n % d == 0 }
end

main if __FILE__ == $PROGRAM_NAME
