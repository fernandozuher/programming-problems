# https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

def main():
    positions_and_velocities = read_numbers()
    print("YES" if kangaroo(positions_and_velocities) else "NO")


def read_numbers():
    return list(map(int, input().split()))


def kangaroo(positions_and_velocities):
    x1, v1, x2, v2 = positions_and_velocities

    if v1 == v2:
        return x1 == x2

    distance_diff = x2 - x1
    velocity_diff = v1 - v2
    return distance_diff * velocity_diff >= 0 and distance_diff % velocity_diff == 0


if __name__ == '__main__':
    main()
