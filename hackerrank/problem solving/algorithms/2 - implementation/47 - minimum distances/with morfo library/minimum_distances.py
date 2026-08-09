# https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input_ln()
    arr = morfo.readln(int, list)
    print(min_distance(arr))


# n: length of arr
# T: O(n)
# S: O(n) extra space
def min_distance(arr):
    last_seen = {}
    min_dist = -1

    for i, x in enumerate(arr):
        if x in last_seen:
            dist = i - last_seen[x]

            if min_dist == -1 or dist < min_dist:
                min_dist = dist
                if min_dist == 1:
                    return 1

        last_seen[x] = i

    return min_dist


if __name__ == '__main__':
    main()
