# https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

def main():
    days = int(input())
    print(viral_advertising(days))


# n: days
# T: O(n)
# S: O(1) extra space
def viral_advertising(days):
    shared, cumulative = 5, 0
    for _ in range(days):
        liked = shared // 2
        shared = liked * 3
        cumulative += liked
    return cumulative


if __name__ == '__main__':
    main()
