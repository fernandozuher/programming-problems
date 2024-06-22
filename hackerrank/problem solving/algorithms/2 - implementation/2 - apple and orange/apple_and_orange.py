# https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

def main():
    data = read_data()
    count_apples_and_oranges(data)


def read_data():
    data = AppleAndOrange()
    data.starting_sam, data.ending_sam = read_int_array()
    data.apple_tree_location, data.orange_tree_location = read_int_array()
    read_int_array()  # Discard sizes of arrays
    data.apples_distance_from_tree = read_int_array()
    data.oranges_distance_from_tree = read_int_array()
    return data


class AppleAndOrange:
    starting_sam = 0
    ending_sam = 0
    apple_tree_location = 0
    orange_tree_location = 0
    apples_distance_from_tree = []
    oranges_distance_from_tree = []


def read_int_array():
    return list(map(int, input().split()))


def count_apples_and_oranges(data):
    apples_on_house = count_fruits_on_house(data, 'apple')
    oranges_on_house = count_fruits_on_house(data, 'orange')
    print(f"{apples_on_house}\n{oranges_on_house}")


def count_fruits_on_house(data, fruit):
    tree_location, fruits = filter_data(data, fruit)
    fruits_on_house = 0

    for partial_location in fruits:
        location = tree_location + partial_location
        if data.starting_sam <= location <= data.ending_sam:
            fruits_on_house += 1

    return fruits_on_house


def filter_data(data, fruit):
    if fruit == 'apple':
        return data.apple_tree_location, data.apples_distance_from_tree
    return data.orange_tree_location, data.oranges_distance_from_tree


if __name__ == '__main__':
    main()
