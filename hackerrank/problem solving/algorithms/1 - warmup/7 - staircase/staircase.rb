# https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

def main
  n = gets.to_i
  staircase(n)
end

  def staircase(n)
    (1..n).each { |i|
      (0...n - i).each {
        print ' '
      }
      (0...i).each {
        print '#'
      }
      puts ''
    }
  end

main
