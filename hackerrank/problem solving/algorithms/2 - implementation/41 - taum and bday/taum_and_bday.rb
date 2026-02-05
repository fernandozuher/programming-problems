# https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

Gifts = Struct.new(:n_black_gifts,
                   :n_white_gifts,
                   :black_gift_cost,
                   :white_gift_cost,
                   :cost_to_convert_between_gifts)

def main
  n = gets.to_i
  n.times { puts min_cost_of_buying_gifts(read_test_case) }
end

def read_test_case
  arr = read_numbers
  arr.concat(read_numbers)
  Gifts.new(*arr)
end

def read_numbers
  gets.split.map(&:to_i)
end

# T: O(1)
# S: O(1) extra space
def min_cost_of_buying_gifts(x)
  black_cost = [x.black_gift_cost, x.white_gift_cost + x.cost_to_convert_between_gifts].min
  white_cost = [x.white_gift_cost, x.black_gift_cost + x.cost_to_convert_between_gifts].min
  x.n_black_gifts * black_cost + x.n_white_gifts * white_cost
end

main if __FILE__ == $0
