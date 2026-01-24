# https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

def main():
    initial_state = read_numbers()
    print("YES" if kangaroo(initial_state) else "NO")


def read_numbers():
    return list(map(int, input().split()))


# T: O(1)
# S: O(1) extra space
def kangaroo(initial_state):
    x1, v1, x2, v2 = initial_state

    if v1 == v2:
        return x1 == x2

    distance_diff = x2 - x1
    velocity_diff = v1 - v2
    return distance_diff * velocity_diff >= 0 and distance_diff % velocity_diff == 0


if __name__ == '__main__':
    main()
