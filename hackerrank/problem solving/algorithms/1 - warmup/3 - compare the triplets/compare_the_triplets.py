# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

def main():
    array1 = read_int_array()
    array2 = read_int_array()
    player1, player2 = compare_triplets(array1, array2)
    print(f"{player1} {player2}")


def read_int_array():
    return list(map(int, input().split()))


def compare_triplets(array1, array2):
    player1, player2 = 0, 0

    for p1, p2 in zip(array1, array2):
        if p1 > p2:
            player1 += 1
        elif p2 > p1:
            player2 += 1

    return [player1, player2]


if __name__ == '__main__':
    main()
