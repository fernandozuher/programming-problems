# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main():
    _n = int(input())
    array = read_int_array()
    print(sock_merchant(array))


def read_int_array():
    return list(map(int, input().split()))


def sock_merchant(socks):
    pairs = 0
    socks_pairing = {}

    for sock in socks:
        if socks_pairing.get(sock):
            pairs += 1
        socks_pairing[sock] = not socks_pairing[sock] if socks_pairing.get(sock) is not None else True

    return pairs


if __name__ == '__main__':
    main()
