# Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

def solution(n_counters, array)
    found_max_counter = false
    max = 0
    current_max = 0
    counters = Hash.new

    for element in array
        if element <= n_counters
            if found_max_counter
                counters, found_max_counter, current_max = default_zero_values
            end

            increment_counter(element, counters)
            if counters[element] > current_max
                current_max += 1
            end
        elsif !found_max_counter
            max += current_max
            found_max_counter = true
        end
    end

    compouse_result(found_max_counter, max, n_counters, counters)
end

    def default_zero_values
        counters = Hash.new
        found_max_counter = false
        current_max = 0
        [counters, found_max_counter, current_max]
    end

    def increment_counter(counter, counters)
        if !counters.include?(counter)
            counters[counter] = 0
        end
        counters[counter] += 1
    end

    def compouse_result(found_max_counter, max, n_counters, counters)
        initial_value = (found_max_counter || max > 0) ? max : 0
        result = Array.new(n_counters + 1, initial_value)

        if !found_max_counter
            counters.each do |counter, value|
                result[counter] += value
            end
        end

        result[1...]
    end
