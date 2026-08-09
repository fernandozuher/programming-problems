# https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input_ln()
    arr = morfo.readln(int, list)
    arr.sort()
    print(*cut_the_sticks(arr), sep='\n')


# n: length of arr
# k: number of distinct values in arr
# k <= n
# T: O(n)
#    Sorting arr beforehand is O(n log n)
# S: O(k) = O(n) extra space
#    Sorting arr beforehand is O(n) extra space
def cut_the_sticks(arr):
    res = []
    slow, n = 0, len(arr)

    for fast in range(n):
        if arr[slow] == arr[fast]:
            continue
        res.append(n - slow)
        slow = fast
    res.append(n - slow)

    return res


if __name__ == '__main__':
    main()
