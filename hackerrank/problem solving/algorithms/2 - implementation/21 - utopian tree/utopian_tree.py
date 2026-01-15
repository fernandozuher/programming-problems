# https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

def main():
    n = int(input())
    utopian_tree = generate_heights_utopian_tree()
    for _ in range(n):
        cycles = int(input())
        print(utopian_tree[cycles])


# k: length of output array heights = 61
# T: O(k) = O(61) = O(1). S: O(61) = O(1) extra space.
def generate_heights_utopian_tree():
    max_cycles = 60
    heights = [0] * (max_cycles + 1)
    height = 0
    for cycle in range(max_cycles + 1):
        height += height if is_cycle_happening_during_spring(cycle) else 1
        heights[cycle] = height
    return heights


def is_cycle_happening_during_spring(cycle):
    return cycle & 1


if __name__ == '__main__':
    main()
