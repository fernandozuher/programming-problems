# https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

def main():
    n = int(input())
    for _ in range(n):
        _, threshold = read_numbers()
        arrival_times = read_numbers()
        print("YES" if angry_professor(arrival_times, threshold) else "NO")


def read_numbers():
    return list(map(int, input().split()))


# k: length of array arrival_times
# T: O(k)
# S: O(1) extra space
def angry_professor(arrival_times, threshold):
    on_time = sum(t <= 0 for t in arrival_times)
    return on_time < threshold


if __name__ == '__main__':
    main()
