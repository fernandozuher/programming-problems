# https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

def main():
    _, beautiful_difference = read_numbers()
    arr = read_numbers()
    print(find_beautiful_triplets(arr, beautiful_difference))


def read_numbers():
    return list(map(int, input().split()))


# n: length of arr
# k: distinct numbers of arr
# k <= n
# T: O(n)
# S: O(k) = O(n) extra space
def find_beautiful_triplets(arr, beautiful_difference):
    values = set(arr)
    double_bd = 2 * beautiful_difference
    return sum(x + beautiful_difference in values and x + double_bd in values for x in arr)


if __name__ == '__main__':
    main()
