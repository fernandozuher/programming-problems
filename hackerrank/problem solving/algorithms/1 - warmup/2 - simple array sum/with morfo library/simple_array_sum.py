# https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input_ln()
    print(sum_stdin())


# n: number of integers in the input line
# T: O(n)
# S: O(n) extra space
def sum_stdin():
    return sum(morfo.readln(int, list))


if __name__ == '__main__':
    main()
