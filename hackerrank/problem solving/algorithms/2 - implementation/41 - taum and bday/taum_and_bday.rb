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
  array = read_numbers
  array += read_numbers
  Gifts.new(*array)
end

def read_numbers
  gets.split.map(&:to_i)
end

def min_cost_of_buying_gifts(gifts)
  black_cost = [gifts.black_gift_cost, gifts.white_gift_cost + gifts.cost_to_convert_between_gifts].min
  white_cost = [gifts.white_gift_cost, gifts.black_gift_cost + gifts.cost_to_convert_between_gifts].min
  gifts.n_black_gifts * black_cost + gifts.n_white_gifts * white_cost
end

main if __FILE__ == $PROGRAM_NAME
