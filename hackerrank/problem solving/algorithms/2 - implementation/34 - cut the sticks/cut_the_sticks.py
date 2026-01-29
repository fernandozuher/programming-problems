# https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main():
    input()
    arr = read_numbers()
    arr.sort()
    print(*cut_the_sticks(arr), sep='\n')


def read_numbers():
    return list(map(int, input().split()))


# n: length of arr
# k: number of distinct values in arr
# T: O(n)
#    Sorting arr before calling this function is O(n log n)
# S: O(k), but O(n) in the worst case extra space
#    Sorting arr before calling this function is O(n) extra space
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
