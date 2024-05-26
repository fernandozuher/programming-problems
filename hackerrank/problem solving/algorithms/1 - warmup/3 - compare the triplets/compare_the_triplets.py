# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

def main():

    array1 = read_int_array()
    array2 = read_int_array()
    result = compare_triplets(array1, array2)
    print(f"{result[0]} {result[1]}")


def read_int_array():

    return list(map(int, input().split()))


def compare_triplets(array1, array2):

    player1, player2 = 0, 0

    for val1, val2 in zip(array1, array2):
        if val1 > val2:
            player1 += 1
        elif val2 > val1:
            player2 += 1

    return [player1, player2]


if __name__ == '__main__':
    main()
