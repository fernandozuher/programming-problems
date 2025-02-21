# https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

from sys import stdin


def main():
    n = int(input())
    phone_book = init_phone_book(n)
    query_names(phone_book)


def init_phone_book(n):
    phone_book = {}
    for _ in range(n):
        name, phone = input().split()
        phone_book[name] = phone
    return phone_book


def query_names(phone_book):
    for name in stdin:
        name = name.rstrip()
        if value := phone_book.get(name):
            print(f"{name}={value}")
        else:
            print('Not found')


if __name__ == '__main__':
    main()
