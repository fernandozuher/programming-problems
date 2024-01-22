# https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

def main():

    n = int(input())
    array = input()
    obj = CountValleys(array)
    print(obj.traversed_valleys())


class CountValleys:

    def __init__(self, steps):

        self._steps = steps
        self._traversed_valleys = 0
        self._counting_valleys()


    def _counting_valleys(self):

        current_altitude = 0

        for step in self._steps:
            was_travessing_a_valley = current_altitude < 0
            current_altitude += -1 if step == 'D' else 1

            if self._is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude):
                self._traversed_valleys += 1


    def _is_in_sea_level_from_valley(self, was_travessing_a_valley, current_altitude):

        return was_travessing_a_valley and not current_altitude


    def traversed_valleys(self):

        return self._traversed_valleys


if __name__ == "__main__":
    main()
