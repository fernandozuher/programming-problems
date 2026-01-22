# https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

def main():
    _, jump_length = read_numbers()
    arr = read_numbers()
    print(jumping_on_the_clouds(arr, jump_length))


def read_numbers():
    return list(map(int, input().split()))


# n: length of array clouds; 2 to 25
# k (jump_length): 1 <= k <= n
# n % k = 0
# c[i] = 0 or 1
# T: O(n) = O(25) = O(1)
# S: O(1) extra space
def jumping_on_the_clouds(clouds, jump_length):
    energy = 100
    cloud_index = 0

    while True:
        energy -= 3 if clouds[cloud_index] else 1
        cloud_index = (cloud_index + jump_length) % len(clouds)
        if cloud_index == 0:
            break

    return energy


if __name__ == '__main__':
    main()
