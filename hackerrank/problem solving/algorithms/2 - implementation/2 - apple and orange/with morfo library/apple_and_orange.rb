# https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

require 'morfo'

Struct.new("House", :house_start, :house_end) do
  def contains(position) = house_start <= position && position <= house_end
end

Struct.new("FruitTree", :tree_location, :fruit_distances)

def main
  house, apple_tree, orange_tree = read_input
  puts count_fruits_on_house(apple_tree, house)
  puts count_fruits_on_house(orange_tree, house)
end

def read_input
  house_start = Morfo.read(&:to_i)
  house_end = Morfo.read(&:to_i)
  house = Struct::House.new(house_start, house_end)

  apple_tree_location = Morfo.read(&:to_i)
  orange_tree_location = Morfo.read(&:to_i)

  n_apples = Morfo.read(&:to_i)
  n_oranges = Morfo.read(&:to_i)
  apple_distances = Morfo.read(n_apples, &:to_i)
  orange_distances = Morfo.read(n_oranges, &:to_i)

  apple_tree = Struct::FruitTree.new(apple_tree_location, apple_distances)
  orange_tree = Struct::FruitTree.new(orange_tree_location, orange_distances)

  [house, apple_tree, orange_tree]
end

# n: length of fruit_tree.fruit_distances
# T: O(n)
# S: O(1) extra space
def count_fruits_on_house(fruit_tree, house)
  fruit_tree.fruit_distances.count { house.contains(fruit_tree.tree_location + _1) }
end

main if __FILE__ == $0
