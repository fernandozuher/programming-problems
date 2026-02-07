# https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

def main():
    _, beautiful_difference = read_numbers()
    arr = read_numbers()
    print(find_beautiful_triplets(arr, beautiful_difference))


def read_numbers():
    return list(map(int, input().split()))


# n: length of array arr
# T: O(n)
# S: O(n) extra space
def find_beautiful_triplets(arr, beautiful_difference):
    values = set(arr)
    double_bd = 2 * beautiful_difference
    return sum(1 for x in arr if x + beautiful_difference in values and x + double_bd in values)


if __name__ == '__main__':
    main()
