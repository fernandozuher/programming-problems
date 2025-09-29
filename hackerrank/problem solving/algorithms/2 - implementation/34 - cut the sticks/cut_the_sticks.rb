# https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main
  gets
  arr = read_numbers.sort!
  puts cut_the_sticks(arr)
end

def read_numbers
  gets.split.map(&:to_i)
end

def cut_the_sticks(arr)
  res = []
  i = 0
  n = arr.length
  while i < n
    res << (n - i)
    shortest = arr[i]
    i += 1 while i < n && arr[i] == shortest
  end
  res
end

main if __FILE__ == $PROGRAM_NAME
