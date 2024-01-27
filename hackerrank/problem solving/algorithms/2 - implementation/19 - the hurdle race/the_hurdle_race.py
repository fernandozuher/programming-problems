# https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

def main():

    n, maximum_height_can_jump = read_int_array()
    hurdles_heights = read_int_array()
    obj = Hurdle_race(hurdles_heights, maximum_height_can_jump)
    print(obj.doses())


def read_int_array():

    return list(map(int, input().split()))


class Hurdle_race:

    def __init__(self, hurdles_heights, maximum_height_can_jump):

        self._hurdles_heights = hurdles_heights
        self._maximum_height_can_jump = maximum_height_can_jump
        self._doses = 0
        self._hurdle_race()


    def _hurdle_race(self):

        highest_hurdle = max(self._hurdles_heights)
        self._doses = highest_hurdle - self._maximum_height_can_jump if highest_hurdle > self._maximum_height_can_jump else 0


    def doses(self):

        return self._doses


if __name__ == "__main__":
    main()
