# https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

def main
  n_tests = gets.to_i rescue 0
  process_prime_tests(n_tests)
end

def process_prime_tests(n_tests)
  n_tests.times do
    n = gets.to_i rescue 0
    puts prime?(n) ? 'Prime' : 'Not prime'
  end
end

def prime?(n)
  if n <= 1
    return false
  end
  if n == 2
    return true
  end
  if n % 2 == 0
    return false
  end

  limit = Math.sqrt(n).to_i
  (3..limit).step(2).each { |divisor|
    if n % divisor == 0
      return false
    end
  }
  true
end

main
