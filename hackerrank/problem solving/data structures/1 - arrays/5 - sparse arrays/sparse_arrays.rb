# https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

def main
  n = gets.to_i
  strings = read_lines(n)
  strings_to_counts = strings.tally

  n = gets.to_i
  queries = read_lines(n)

  puts counts_from(strings_to_counts, queries)
end

def read_lines(n)
  n.times.map { gets.strip }
end

# n: length of queries
# max_query_string_length: 20
# T: O(n * max_query_string_length) = O(n * 20) = O(n)
# S: O(n) extra space
def counts_from(freq_map, queries)
  queries.map { |q| freq_map[q] || 0 }
end

main if __FILE__ == $0
