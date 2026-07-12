# https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

def main():
    input()
    print(sum_stdin())


# n: number of integers in the input line
# T: O(n)
# S: O(n) extra space
def sum_stdin():
    return sum(map(int, input().split()))


if __name__ == '__main__':
    main()
