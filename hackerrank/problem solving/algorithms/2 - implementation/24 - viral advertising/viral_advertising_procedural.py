# Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

def main():

    days = int(input())
    cumulativeLikes = viralAdvertising(days)
    print(cumulativeLikes)


def viralAdvertising(days):

    shared, liked, cumulative = 5, 0, 0

    for _ in range(days):
        liked = int(shared / 2)
        cumulative += liked
        shared = liked * 3

    return cumulative


if __name__ == "__main__":
    main()
