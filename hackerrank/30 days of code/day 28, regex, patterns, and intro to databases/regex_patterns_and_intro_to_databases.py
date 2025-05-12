# https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

def main():
    n = int(input())
    names = collect_gmail_users(n)
    names.sort()
    print(*names, sep='\n')


def collect_gmail_users(n):
    names = []

    for _ in range(n):
        name, email = input().split()
        if email.endswith('@gmail.com'):
            names.append(name)

    return names


if __name__ == '__main__':
    main()
