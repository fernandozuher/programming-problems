# https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

def main():
    input()
    arr = read_numbers()
    print(a_very_big_sum(arr))


def read_numbers():
    return list(map(int, input().split()))


# n: length of arr
# T: O(n)
# S: O(1) extra space
def a_very_big_sum(arr):
    return sum(arr)


if __name__ == '__main__':
    main()
