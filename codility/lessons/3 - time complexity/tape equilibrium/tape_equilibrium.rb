# Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

def solution(array)
    first_part = array.first
    second_part = array.sum - first_part
    minimum_difference_between_parts = (first_part - second_part).abs

    for element in array[1...-1]
        first_part += element
        second_part -= element
        current_minimum = (first_part - second_part).abs
        minimum_difference_between_parts = [minimum_difference_between_parts, current_minimum].min
    end

    minimum_difference_between_parts
end
