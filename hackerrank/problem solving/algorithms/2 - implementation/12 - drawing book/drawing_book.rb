# https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

def main
  n = gets.to_i
  page = gets.to_i
  puts count_page(n, page)
end

def count_page(n, page)
  from_front = page / 2
  from_back = n / 2 - from_front
  [from_front, from_back].min
end

main
