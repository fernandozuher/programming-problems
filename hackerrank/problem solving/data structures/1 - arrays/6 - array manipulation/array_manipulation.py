# https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

def main():

    n, n_queries = read_int_array()
    print(array_manipulation(n, n_queries))


def read_int_array():

    return list(map(int, input().split()))


def array_manipulation(n, n_queries):

    array = [0] * (n + 2) # n + 2 = 1-indexed array + range-end

    for i in range (n_queries):
        b, e, summand = read_int_array()
        array[b] += summand
        array[e + 1] -= summand

    sum = 0
    max_sum = 0
    for x in array:
        if x == 0:
            continue
        sum += x
        max_sum = max(max_sum, sum)
    
    return max_sum


if __name__ == '__main__':
    main()
