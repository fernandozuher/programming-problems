#!/bin/python3

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

def verifyFruitLocation(s, t, treeLocation, partialLocation):
    location = treeLocation + partialLocation
    return location >= s and location <= t

def countFruitsOnHouse(s, t, treeLocation, fruits):
    return sum(verifyFruitLocation(s, t, treeLocation, partialLocation) for partialLocation in fruits)

def countApplesAndOranges(s, t, a, b, apples, oranges):
    applesOnHouse = countFruitsOnHouse(s, t, a, apples)
    orangesOnHouse = countFruitsOnHouse(s, t, b, oranges)
    print(f"{applesOnHouse}\n{orangesOnHouse}")

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    s = int(first_multiple_input[0])

    t = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()

    a = int(second_multiple_input[0])

    b = int(second_multiple_input[1])

    third_multiple_input = input().rstrip().split()

    m = int(third_multiple_input[0])

    n = int(third_multiple_input[1])

    apples = list(map(int, input().rstrip().split()))

    oranges = list(map(int, input().rstrip().split()))

    countApplesAndOranges(s, t, a, b, apples, oranges)
