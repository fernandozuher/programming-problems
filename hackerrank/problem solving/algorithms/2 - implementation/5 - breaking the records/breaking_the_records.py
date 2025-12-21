# https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

def main():
    input()
    print(*breaking_records(read_numbers()))


def read_numbers():
    return list(map(int, input().split()))


def breaking_records(scores):
    most_points, least_points = scores[0], scores[0]
    most_record_breaks, least_record_breaks = 0, 0

    for score in scores[1:]:
        if score > most_points:
            most_points = score
            most_record_breaks += 1
        elif score < least_points:
            least_points = score
            least_record_breaks += 1

    return most_record_breaks, least_record_breaks


if __name__ == '__main__':
    main()
