# https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

def main():

    input = read_input()
    count_apples_and_oranges(input)


def read_input():

    starting_sam, ending_sam = read_int_array()
    apple_tree_location, orange_tree_location = read_int_array()

    # Discard sizes of arrays
    read_int_array()

    apples_distance_from_tree = read_int_array()
    oranges_distance_from_tree = read_int_array()

    return AppleAndOrange(starting_sam, ending_sam,
                            apple_tree_location, orange_tree_location,
                            apples_distance_from_tree, oranges_distance_from_tree)


def read_int_array():

    return list(map(int, input().split()))


def count_apples_and_oranges(input):

    apples_on_house = count_fruits_on_house(input, 'apple')
    oranges_on_house = count_fruits_on_house(input, 'orange')
    print(f"{apples_on_house}\n{oranges_on_house}")


def count_fruits_on_house(input, fruit):

    filtered_input = filter_input(input, fruit)
    tree_location = filtered_input[0]
    fruits = filtered_input[1]

    sum = 0
    for partial_location in fruits:
        location = tree_location + partial_location
        if location >= input.starting_sam and location <= input.ending_sam:
            sum += 1

    return sum


def filter_input(input, fruit):

    DATA = 2
    filtered_input = [None] * DATA

    if fruit == 'apple':
        filtered_input[0] = input.apple_tree_location
        filtered_input[1] = input.apples_distance_from_tree
    else:
        filtered_input[0] = input.orange_tree_location
        filtered_input[1] = input.oranges_distance_from_tree

    return filtered_input


class AppleAndOrange:
    
    def __init__(self, starting_sam, ending_sam, apple_tree_location, orange_tree_location,
        apples_distance_from_tree, oranges_distance_from_tree):

        self.starting_sam = starting_sam
        self.ending_sam = ending_sam
        self.apple_tree_location = apple_tree_location
        self.orange_tree_location = orange_tree_location
        self.apples_distance_from_tree = apples_distance_from_tree
        self.oranges_distance_from_tree = oranges_distance_from_tree


if __name__ == '__main__':
    main()
