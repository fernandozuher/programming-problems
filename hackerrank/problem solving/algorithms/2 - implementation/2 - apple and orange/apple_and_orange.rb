#!/bin/ruby

#
# Complete the 'countApplesAndOranges' function below.
#
# The function accepts following parameters:
#  1. INTEGER s
#  2. INTEGER t
#  3. INTEGER a
#  4. INTEGER b
#  5. INTEGER_ARRAY apples
#  6. INTEGER_ARRAY oranges
#

def countFruitsOnHouse s, t, treeLocation, fruits
    verifyFruitLocation = -> (s, t, treeLocation, partialLocation) {
        location = treeLocation + partialLocation
        location >= s && location <= t
    }
    fruits.count {|partialLocation| verifyFruitLocation.call(s, t, treeLocation, partialLocation)}
end

def countApplesAndOranges s, t, a, b, apples, oranges
    applesOnHouse = countFruitsOnHouse s, t, a, apples
    orangesOnHouse = countFruitsOnHouse s, t, b, oranges
    puts "#{applesOnHouse}\n#{orangesOnHouse}"
end

first_multiple_input = gets.rstrip.split

s = first_multiple_input[0].to_i

t = first_multiple_input[1].to_i

second_multiple_input = gets.rstrip.split

a = second_multiple_input[0].to_i

b = second_multiple_input[1].to_i

third_multiple_input = gets.rstrip.split

m = third_multiple_input[0].to_i

n = third_multiple_input[1].to_i

apples = gets.rstrip.split.map(&:to_i)

oranges = gets.rstrip.split.map(&:to_i)

countApplesAndOranges s, t, a, b, apples, oranges
