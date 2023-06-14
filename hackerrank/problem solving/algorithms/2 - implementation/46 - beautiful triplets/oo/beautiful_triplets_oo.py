# Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

def main():

    SIZE, BEAUTIFUL_DIFFERENCE = read_an_array()
    ARRAY = read_an_array()

    OBJ = BeatifulTriplets(ARRAY, BEAUTIFUL_DIFFERENCE)
    print(OBJ.get_n_beautiful_triplets())


def read_an_array():

    ARRAY = list(map(int, input().split()))
    return ARRAY


class BeatifulTriplets:

    def __init__(self, array, beautiful_difference):

        self._array = array
        self._beautiful_difference = beautiful_difference
        self._find_beautiful_triplets()


    def _find_beautiful_triplets(self):

        self._n_beautiful_triplets = 0

        if len(self._array) > 2:
            for i in range(0, len(self._array)-2):
                for j in range(i+1, len(self._array)-1):
                    FIRST_DIFFERENCE = self._array[j] - self._array[i]

                    if FIRST_DIFFERENCE < self._beautiful_difference:
                        continue
                    elif FIRST_DIFFERENCE > self._beautiful_difference:
                        break
                    
                    for k in range(j+1, len(self._array)):
                        SECOND_DIFFERENCE = self._array[k] - self._array[j]

                        if SECOND_DIFFERENCE == self._beautiful_difference:
                            self._n_beautiful_triplets += 1
                        elif SECOND_DIFFERENCE > self._beautiful_difference:
                            break


    def get_n_beautiful_triplets(self):

        return self._n_beautiful_triplets


if __name__ == "__main__":
    main()
