# https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main():
    input()
    arr = read_numbers()
    print(*sequence_equation(arr), sep='\n')


def read_numbers():
    return list(map(int, input().split()))


# n: length of array arr/output
# T: O(n)
# S: O(n) extra space
def sequence_equation(arr):
    values_to_index = [0] * len(arr)
    for i, val in enumerate(arr):
        values_to_index[val - 1] = i

    return [values_to_index[v] + 1 for v in values_to_index]


if __name__ == '__main__':
    main()
