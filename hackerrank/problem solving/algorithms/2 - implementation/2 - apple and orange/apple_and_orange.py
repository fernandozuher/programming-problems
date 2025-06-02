# https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

from dataclasses import dataclass


def main():
    house, apple_tree, orange_tree = read_input()
    print(count_fruits_on_house(apple_tree, house))
    print(count_fruits_on_house(orange_tree, house))


def read_input():
    house_start, house_end = read_numbers()
    house = House(house_start, house_end)

    apple_tree_location, orange_tree_location = read_numbers()
    input()  # Discard array sizes
    apple_distances = read_numbers()
    orange_distances = read_numbers()

    apple_tree = FruitTree(apple_tree_location, apple_distances)
    orange_tree = FruitTree(orange_tree_location, orange_distances)

    return [house, apple_tree, orange_tree]


@dataclass
class House:
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def contains(self, position):
        return self.start <= position <= self.end


@dataclass
class FruitTree:
    def __init__(self, tree_location, fruit_distances):
        self.tree_location = tree_location
        self.fruit_distances = fruit_distances


def read_numbers():
    return list(map(int, input().split()))


def count_fruits_on_house(fruit_tree, house):
    return sum(
        house.contains(fruit_tree.tree_location + distance)
        for distance in fruit_tree.fruit_distances
    )


if __name__ == '__main__':
    main()
