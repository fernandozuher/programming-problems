# https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

def main
  n = gets.to_i
  staircase(n)
end

def staircase(n)
  n.times do |i|
    hashes = '#' * (i + 1)
    puts hashes.rjust(n)
  end
end

main
