# https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input_ln()
    print(*breaking_records(morfo.readln(int, list)))


# n: length of scores
# T: O(n)
# S: O(1) extra space
def breaking_records(scores):
    most_points, least_points = scores[0], scores[0]
    most_record_breaks, least_record_breaks = 0, 0

    for score in scores:
        if score > most_points:
            most_points = score
            most_record_breaks += 1
        elif score < least_points:
            least_points = score
            least_record_breaks += 1

    return most_record_breaks, least_record_breaks


if __name__ == '__main__':
    main()
