# https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

def main():

    days = int(input())
    print(viral_advertising(days))
''

def viral_advertising(days):

    shared, liked, cumulative = 5, 0, 0

    for _ in range(days):
        liked = int(shared / 2)
        cumulative += liked
        shared = liked * 3

    return cumulative


if __name__ == '__main__':
    main()
