# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

# n = test cases
# T = O(n)
# S = O(1)
def main():
    n = int(input())
    for i in range(n):
        prisoners, sweets, start_chair = read_numbers()
        print(save_the_prisoner(prisoners, sweets, start_chair))


# n = size of elements to be read
# T = O(n)
# S = O(n)
def read_numbers():
    return list(map(int, input().split()))


# T = O(1)
# S = O(1)
def save_the_prisoner(prisoners, sweets, start_chair):
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1


if __name__ == '__main__':
    main()
