# Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

def solution(n_counters, array):

    found_max_counter = False
    max = 0
    current_max = 0
    counters = {}

    for element in array:
        if element <= n_counters:
            if found_max_counter:
                counters, found_max_counter, current_max = default_zero_values()

            increment_counter(element, counters)
            if counters[element] > current_max:
                current_max += 1

        elif not found_max_counter:
            max += current_max
            found_max_counter = True

    return compouse_result(found_max_counter, max, n_counters, counters)


def default_zero_values():

    COUNTERS = {}
    FOUND_MAX_COUNTER = False
    CURRENT_MAX = 0
    return [COUNTERS, FOUND_MAX_COUNTER, CURRENT_MAX]


def increment_counter(counter, counters):

    if counter not in counters:
        counters[counter] = 0
    counters[counter] += 1


def compouse_result(found_max_counter, max, n_counters, counters):

    INITIAL_VALUE = max if (found_max_counter or max > 0) else 0
    RESULT = [INITIAL_VALUE] * (n_counters + 1)

    if not found_max_counter:
        for counter, value in counters.items():
            RESULT[counter] += value

    return RESULT[1:]
