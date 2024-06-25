# https://www.hackerrank.com/challenges/between-two-sets/problem?is_full_screen=true

def main
  read_int_array
  set_a = read_int_array
  set_b = read_int_array

  set_a = set_a.sort
  set_b = set_b.sort

  obj = BetweenTwoSets.new(set_a, set_b)
  obj.find_factors
  p obj.total_factors
end

  def read_int_array
    gets.split.map(&:to_i)
  end
  
  class BetweenTwoSets
    attr_reader :total_factors
  
    def initialize(set_a, set_b)
      @set_a = set_a
      @set_b = set_b
      @potential_factors = Array.new
      @total_factors = 0
    end
  
    def find_factors
      find_numbers_divisible_by_set_a
      find_factors_of_set_b
      count_factors
    end
  
      private def find_numbers_divisible_by_set_a
        (@set_a.last..@set_b.first).step(@set_a.last).each { |potential_factor|
          @is_a_real_potential_factor = true
    
          @set_a.each { |x|
            if (potential_factor % x) != 0
              @is_a_real_potential_factor = false
              break
            end
          }
    
          if @is_a_real_potential_factor
            @potential_factors.push(potential_factor)
          end
        }
      end
    
      private def find_factors_of_set_b
        @set_b.each { |x|
          @potential_factors.each_with_index { |potential_factor, i|
            if potential_factor != 0 && (x % potential_factor) != 0
              @potential_factors[i] = 0
            end
          }
        }
      end
    
      private def count_factors
        @total_factors = @potential_factors.count(&:nonzero?)
      end
    end

main