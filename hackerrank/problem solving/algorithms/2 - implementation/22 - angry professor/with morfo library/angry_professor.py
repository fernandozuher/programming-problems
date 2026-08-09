# https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

import morfo


def main():
    n = morfo.read(int)
    for _ in range(n):
        morfo.skip_input()
        threshold = morfo.read(int)
        arrival_times = morfo.readln(int, list)
        print("YES" if angry_professor(arrival_times, threshold) else "NO")


# k: length of arrival_times
# T: O(k)
# S: O(1) extra space
def angry_professor(arrival_times, threshold):
    on_time = sum(t <= 0 for t in arrival_times)
    return on_time < threshold


if __name__ == '__main__':
    main()
