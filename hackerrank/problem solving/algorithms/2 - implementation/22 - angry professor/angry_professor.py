# https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

def main():
    n = int(input())
    cancelled_classes = [None] * n

    for i in range(n):
        _, cancellation_threshold = read_numbers()
        students_arrival_times = read_numbers()
        cancelled_classes[i] = angry_professor(students_arrival_times, cancellation_threshold)

    print(*cancelled_classes, sep='\n')


def read_numbers():
    return list(map(int, input().split()))


def angry_professor(arrival_times, cancellation_threshold):
    on_time = sum(1 for t in arrival_times if t <= 0)
    return "YES" if on_time < cancellation_threshold else "NO"


if __name__ == '__main__':
    main()
