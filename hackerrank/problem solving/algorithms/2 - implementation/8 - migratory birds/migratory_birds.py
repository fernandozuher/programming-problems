# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

from more_itertools import windowed


def main():
    int(input())
    array = read_int_array()
    array.sort()
    print(find_most_spotted_bird(array))


def read_int_array():
    return list(map(int, input().split()))


def find_most_spotted_bird(bird_sightings):
    most_spotted_bird = bird_sightings[0]
    count_most_spotted_bird = 1
    temp_count_most_spotted_bird = 1

    for current_bird, next_bird in windowed(bird_sightings, 2):
        if current_bird == next_bird:
            temp_count_most_spotted_bird += 1
        elif temp_count_most_spotted_bird > count_most_spotted_bird:
            most_spotted_bird = current_bird
            count_most_spotted_bird = temp_count_most_spotted_bird
            temp_count_most_spotted_bird = 1

    if temp_count_most_spotted_bird > count_most_spotted_bird:
        most_spotted_bird = bird_sightings[-1]

    return most_spotted_bird


if __name__ == '__main__':
    main()
