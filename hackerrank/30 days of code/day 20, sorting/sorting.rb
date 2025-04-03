# https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

def main
  numbers = read_input
  n_swaps = bubble_sort(numbers)
  puts "Array is sorted in #{n_swaps} swaps."
  puts "First Element: #{numbers.first}"
  puts "Last Element: #{numbers.last}"
end

def read_input
  gets # Skip size of list
  gets.split.map(&:to_i)
end

def bubble_sort(a)
  total_swaps = 0
  n = a.size
  while n > 0
    n_swaps, new_end = sort_slice(a, n)
    total_swaps += n_swaps
    n = new_end
  end
  total_swaps
end

def sort_slice(a, n)
  n_swaps, new_end = 0, 0
  (n - 1).times { |i|
    if a[i] > a[i + 1]
      a[i], a[i + 1] = a[i + 1], a[i]
      n_swaps += 1
      new_end = i + 1
    end
  }
  [n_swaps, new_end]
end

main
