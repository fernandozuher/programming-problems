# https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

from sys import stdin

def main():
    
    phone_book = {}
    N = int(input())

    for i in range(N):
        name, phone = input().split()
        phone_book[name] = phone

    for name in stdin:
        name = name.rstrip()

        if value := phone_book.get(name):
            print(f"{name}={value}")
        else:
            print("Not found")


if __name__ == "__main__":
    main()
