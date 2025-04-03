# https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

def main():
    numbers = read_input()
    n_swaps = bubble_sort(numbers)
    print(f"Array is sorted in {n_swaps} swaps.")
    print(f"First Element: {numbers[0]}")
    print(f"Last Element: {numbers[-1]}")


def read_input():
    input()  # Skip size of list
    return list(map(int, input().split()))


def bubble_sort(l):
    total_swaps = 0
    end = len(l)
    while end > 0:
        n_swaps, new_end = sort_slice(l, end)
        total_swaps += n_swaps
        end = new_end
    return total_swaps


def sort_slice(l, end):
    n_swaps, new_end = 0, 0
    for i in range(0, len(l) - 1):
        if l[i] > l[i + 1]:
            l[i], l[i + 1] = l[i + 1], l[i]
            n_swaps += 1
            new_end = i + 1
    return n_swaps, new_end


if __name__ == '__main__':
    main()
