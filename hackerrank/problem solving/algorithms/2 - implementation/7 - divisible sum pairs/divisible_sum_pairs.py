# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main():

    n, k = read_int_array()
    array = read_int_array()

    array.sort()

    obj = SubarrayDivision(array, k)
    print(obj.n_divisible_sum_pairs())


def read_int_array():

    return list(map(int, input().split()))


class SubarrayDivision:

    def __init__(self, array, k):
        
        self._array = array
        self._k = k
        self._n_divisible = 0

        self._divisible_sum_pairs()


    def _divisible_sum_pairs(self):

        for i in range(0, len(self._array) - 1):
            for j in range(i + 1, len(self._array)):
                if self._array[i] <= self._array[j] and (self._array[i] + self._array[j]) % self._k == 0:
                    self._n_divisible += 1


    def n_divisible_sum_pairs(self):
        
        return self._n_divisible


if __name__ == "__main__":
    main()
