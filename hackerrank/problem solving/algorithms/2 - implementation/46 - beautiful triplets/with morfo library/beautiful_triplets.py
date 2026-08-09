# https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input()
    beautiful_difference = morfo.read(int)
    arr = morfo.readln(int, list)
    print(find_beautiful_triplets(arr, beautiful_difference))


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
