# https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

def main():
    n = int(input())
    for i in range(n):
        _, threshold = read_numbers()
        students_arrival_times = read_numbers()
        print("YES" if angry_professor(students_arrival_times, threshold) else "NO")        


def read_numbers():
    return list(map(int, input().split()))


def angry_professor(arrival_times, threshold):
    on_time = sum(1 for t in arrival_times if t <= 0)
    return on_time < threshold


if __name__ == '__main__':
    main()
