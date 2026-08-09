# https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

from dataclasses import dataclass

import morfo


@dataclass
class House:
    start: int
    end: int

    def contains(self, position):
        return self.start <= position <= self.end


@dataclass
class FruitTree:
    tree_location: int
    fruit_distances: list[int]


def main():
    house, apple_tree, orange_tree = read_input()
    print(count_fruits_on_house(apple_tree, house))
    print(count_fruits_on_house(orange_tree, house))


def read_input():
    house_start = morfo.read(int)
    house_end = morfo.read(int)
    house = House(house_start, house_end)

    apple_tree_location = morfo.read(int)
    orange_tree_location = morfo.read(int)

    n_apples = morfo.read(int)
    n_oranges = morfo.read(int)
    apple_distances = morfo.read(int, n_apples)
    orange_distances = morfo.read(int, n_oranges)

    apple_tree = FruitTree(apple_tree_location, apple_distances)
    orange_tree = FruitTree(orange_tree_location, orange_distances)

    return [house, apple_tree, orange_tree]


# n: length of fruit_tree.fruit_distances
# T: O(n)
# S: O(1) extra space
def count_fruits_on_house(fruit_tree, house):
    return sum(
        house.contains(fruit_tree.tree_location + distance)
        for distance in fruit_tree.fruit_distances
    )


if __name__ == '__main__':
    main()
