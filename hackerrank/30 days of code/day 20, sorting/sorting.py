# https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

def main():

    _ = input()
    a = list(map(int, input().split()))

    print(f"Array is sorted in {bubble_sort(a)} swaps.")
    print(f"First Element: {a[0]}")
    print(f"Last Element: {a[-1]}")


def bubble_sort(a):

    numberOfSwaps = 0

    for n in range (len(a)-1, 0, -1):
        for i in range(n):
            if a[i] > a[i + 1]:
                a[i], a[i + 1] = a[i + 1], a[i]
                numberOfSwaps += 1

        if not numberOfSwaps:
            break

    return numberOfSwaps


if __name__ == '__main__':
    main()
