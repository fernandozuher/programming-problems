# https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

def main
  house, apple_tree, orange_tree = read_input
  puts count_fruits_on_house(apple_tree, house)
  puts count_fruits_on_house(orange_tree, house)
end

def read_input
  house_start, house_end = read_numbers
  house = Struct::House.new(house_start, house_end)

  apple_tree_location, orange_tree_location = read_numbers
  gets # Discard array sizes
  apple_distances = read_numbers
  orange_distances = read_numbers

  apple_tree = Struct::FruitTree.new(apple_tree_location, apple_distances)
  orange_tree = Struct::FruitTree.new(orange_tree_location, orange_distances)

  [house, apple_tree, orange_tree]
end

Struct.new("House", :house_start, :house_end) do
  def contains(position)
    house_start <= position && position <= house_end
  end
end

Struct.new("FruitTree", :tree_location, :fruit_distances)

def read_numbers
  gets.split.map(&:to_i)
end

def count_fruits_on_house(fruit_tree, house)
  fruit_tree.fruit_distances.count do |distance|
    house.contains(fruit_tree.tree_location + distance)
  end
end

main
