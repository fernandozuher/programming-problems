# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main():

    n = int(input())
    array = read_int_array()
    obj = SalesByMatch(array)
    print(obj.pairs())


def read_int_array():

    return list(map(int, input().split()))


class SalesByMatch:

    def __init__(self, socks):

        self._socks = socks
        self._pairs = 0
        self._sockMerchant()


    def _sockMerchant(self):

        socksPairing = {}

        for sock in self._socks:
            if socksPairing.get(sock):
                self._pairs += 1
            socksPairing[sock] = not socksPairing[sock] if socksPairing.get(sock) != None else True


    def pairs(self):

        return self._pairs


if __name__ == "__main__":
    main()
