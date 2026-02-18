# https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

def main
  gets
  people_loaf_counts = read_numbers
  min_loaves = min_loaves_to_satisfy_rules(people_loaf_counts)
  puts min_loaves == -1 ? 'NO' : min_loaves
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of array people_loaf_counts
# T: O(n)
# S: O(1) extra space
def min_loaves_to_satisfy_rules(people_loaf_counts)
  loaves_given = 0
  counts = people_loaf_counts[0]

  people_loaf_counts.lazy.drop(1).each do |x|
    if counts.odd?
      loaves_given += 2
      counts = x + 1
    else
      counts = x
    end
  end

  counts.odd? ? -1 : loaves_given
end

main if __FILE__ == $0
