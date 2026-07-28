# https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input_ln()
    arr = morfo.readln(int, list)
    print(a_very_big_sum(arr))


# n: length of arr
# T: O(n)
# S: O(1) extra space
def a_very_big_sum(arr):
    return sum(arr)


if __name__ == '__main__':
    main()
