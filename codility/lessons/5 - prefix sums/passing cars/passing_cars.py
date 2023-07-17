# https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

def solution(array):
    passing_cars_pairs = 0
    i, east, passing_cars_limit = 0, 0, 1_000_000_000

    for west in array:
        if west:
            passing_cars_pairs += east
            if passing_cars_pairs > passing_cars_limit:
                return -1
        else:
            east += 1

    return passing_cars_pairs
