# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

def main()
  gets
  puts picking_numbers(read_numbers_into_map)
end

def read_numbers_into_map
  gets.split.map(&:to_i).tally
end

def picking_numbers(counter)
  counter.each_key.inject(0) { |max_len, num| [max_len, counter[num] + (counter[num + 1] || 0)].max }
end

main if __FILE__ == $PROGRAM_NAME
