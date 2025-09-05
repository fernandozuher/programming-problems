# https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main():
    input()
    arr = read_numbers()
    print(*sequence_equation(arr), sep='\n')


def read_numbers():
    return list(map(int, input().split()))


def sequence_equation(arr):
    values_to_index = [0] * len(arr)
    for i, val in enumerate(arr):
        values_to_index[val - 1] = i

    res = [0] * len(arr)
    for i, val in enumerate(values_to_index):
        res[i] = values_to_index[val] + 1

    return res


if __name__ == '__main__':
    main()
