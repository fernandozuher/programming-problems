# https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

from collections import defaultdict

def main():

    n = int(input())
    array = list(map(int, input().split()))
    frequency = defaultdict(int)
    for x in array:
        frequency[x] += 1
    print(equalize_array(frequency, n))


def equalize_array(map, n):

    maximum_quantity_of_equal_element = max(map.values())
    minimum_number_required_deletions = n - maximum_quantity_of_equal_element
    return minimum_number_required_deletions


if __name__ == '__main__':
    main()
