# https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

Gifts = Struct.new(:n_black_gifts,
                   :n_white_gifts,
                   :black_gift_cost,
                   :white_gift_cost,
                   :cost_to_convert_between_gifts)

def main
  n = gets.to_i
  output = Array.new(n).map {
    obj = TaumAndBday.new(read_test_case)
    obj.calculate_minimum_cost_of_buying_gifts
    obj.minimum_cost_of_buying_gifts
  }
  puts output
end

  def read_test_case
    array = read_int_array
    array += read_int_array
    Gifts.new(*array)
  end

    def read_int_array
      gets.split.map(&:to_i)
    end

  class TaumAndBday
    attr_reader :minimum_cost_of_buying_gifts

    def initialize(gifts)
      @gifts = gifts
      @cost_to_convert_from_black_to_white = @gifts.black_gift_cost + @gifts.cost_to_convert_between_gifts
      @cost_to_convert_from_white_to_black = @gifts.white_gift_cost + @gifts.cost_to_convert_between_gifts
      @minimum_cost_of_buying_gifts = 0
    end

    def calculate_minimum_cost_of_buying_gifts
      @minimum_cost_of_buying_gifts = are_original_costs_cheaper_or_equal_than_conversion_between_gifts ?
                                        calculate_minimum_standard_cost : calculate_minimum_cost_in_converting_gifts
    end

      private def are_original_costs_cheaper_or_equal_than_conversion_between_gifts
        @gifts.white_gift_cost <= @cost_to_convert_from_black_to_white &&
          @gifts.black_gift_cost <= @cost_to_convert_from_white_to_black
      end

      private def calculate_minimum_standard_cost
        @gifts.n_black_gifts * @gifts.black_gift_cost + @gifts.n_white_gifts * @gifts.white_gift_cost
      end

      private def calculate_minimum_cost_in_converting_gifts
        total_gifts = @gifts.n_black_gifts + @gifts.n_white_gifts
        if @gifts.white_gift_cost > @cost_to_convert_from_black_to_white
          return total_gifts * @gifts.black_gift_cost + @gifts.n_white_gifts * @gifts.cost_to_convert_between_gifts
        end
        total_gifts * @gifts.white_gift_cost + @gifts.n_black_gifts * @gifts.cost_to_convert_between_gifts
      end
  end

main
