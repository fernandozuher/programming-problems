# https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

def main
    n = gets.to_i
    array = gets.split
    frequency = Hash.new(0)
    array.each do |x|
        frequency[x] += 1
    end
    p equalize_array(frequency, n)
end

    def equalize_array(map, n)
        maximum_quantity_of_equal_element = map.values.max
        minimum_number_required_deletions = n - maximum_quantity_of_equal_element
    end

main
