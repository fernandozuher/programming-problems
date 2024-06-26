# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

def main():
    array = list(map(int, input().split()))
    array.sort()
    min_sum, max_sum = mini_max_sum(array)
    print(f"{min_sum} {max_sum}")


def mini_max_sum(array):
    total_sum = sum(array)
    min_sum = total_sum - array[-1]
    max_sum = total_sum - array[0]
    return min_sum, max_sum


if __name__ == '__main__':
    main()
