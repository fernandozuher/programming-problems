# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

def main()
  gets
  puts picking_numbers(read_numbers)
end

def read_numbers
  gets.split.map(&:to_i)
end

def picking_numbers(numbers)
  counter = numbers.tally
  counter.each_key.inject(0) { |max_len, num| [max_len, counter[num] + (counter[num + 1] || 0)].max }
end

main
