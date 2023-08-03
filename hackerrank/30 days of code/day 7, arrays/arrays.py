# https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

def main():

    _N = int(input())
    ARRAY = list(map(int, input().split()))
    for element in reversed(ARRAY):
        print(f"{element} ", end="")


if __name__ == "__main__":
    main()
