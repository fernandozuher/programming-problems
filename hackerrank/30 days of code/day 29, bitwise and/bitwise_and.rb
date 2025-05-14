# https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

def main
  test_cases = gets.to_i
  test_cases.times do
    n, k = gets.split.map(&:to_i)
    puts bitwise_and(n, k)
  end
end

def bitwise_and(n, k)
  return k - 1 if (k - 1 | k) <= n
  k - 2
end

main
