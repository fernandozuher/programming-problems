# https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

def main():
    input()
    array = read_int_array()
    most_points_records, least_points_records = breaking_records(array)
    print(most_points_records, least_points_records)


def read_int_array():
    return list(map(int, input().split()))


def breaking_records(scores):
    most_points, least_points = scores[0], scores[0]
    breaking_most_points_records, breaking_least_points_records = 0, 0

    for score in scores:
        if score > most_points:
            most_points = score
            breaking_most_points_records += 1
        elif score < least_points:
            least_points = score
            breaking_least_points_records += 1

    return breaking_most_points_records, breaking_least_points_records


if __name__ == '__main__':
    main()
