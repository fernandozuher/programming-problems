# https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

def main
  n_tests = gets.to_i
  n_tests.times do
    n, p = gets.split.map(&:to_i)
    power(n, p)
  end
end

def power(n, p)
  begin
    puts Calculator.power(n, p)
  rescue ArgumentError => e
    puts e.message
  end
end

class Calculator
  def self.power(n, p)
    if n < 0 || p < 0
      raise ArgumentError.new('n and p should be non-negative')
    end
    n ** p
  end
end

main
