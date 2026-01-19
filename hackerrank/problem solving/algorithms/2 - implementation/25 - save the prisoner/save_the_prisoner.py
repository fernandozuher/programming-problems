# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main():
    n = int(input())
    for i in range(n):
        prisoners, sweets, start_chair = read_input()
        print(save_the_prisoner(prisoners, sweets, start_chair))


def read_input():
    return map(int, input().split())


# T: O(1)
# S: O(1) extra space
def save_the_prisoner(prisoners, sweets, start_chair):
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1


if __name__ == '__main__':
    main()
