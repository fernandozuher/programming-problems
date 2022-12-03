#!/bin/python3


def bubbleSort(a):

    numberOfSwaps = 0

    for _ in a:
        for j in range(len(a) - 1):

            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                numberOfSwaps += 1

        if not numberOfSwaps:
            break

    return numberOfSwaps


if __name__ == "__main__":
    input()

    a = list(map(int, input().rstrip().split()))

    print(f"Array is sorted in {bubbleSort(a)} swaps.")
    print(f"First Element: {a[0]}")
    print(f"Last Element: {a[-1]}")
