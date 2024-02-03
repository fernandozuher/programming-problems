# https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

def main():

    starting_day_number, ending_day_number, divisor = read_int_array()
    obj = BeautifulDays(starting_day_number, ending_day_number, divisor)
    print(obj.n_beautiful_days())


def read_int_array():

    return list(map(int, input().split()))


class BeautifulDays:

    def __init__(self, starting_day_number, ending_day_number, divisor):

        self._starting_day_number = starting_day_number
        self._ending_day_number = ending_day_number
        self._divisor = divisor
        self._n_beautiful_days = 0
        self._calculate_beautiful_days_quantity()


    def _calculate_beautiful_days_quantity(self):

        for number in range(self._starting_day_number, self._ending_day_number + 1):
            reverse_number = self._generate_reverse_number(number)
            if self._is_day_beautiful(number, reverse_number):
                self._n_beautiful_days += 1


    def _generate_reverse_number(self, number):

        reverse_number = 0

        while number > 0:
            reverse_number = (reverse_number * 10) + (number % 10)
            number = int(number / 10)

        return reverse_number


    def _is_day_beautiful(self, number, reverse_number):

        return abs(number - reverse_number) % self._divisor == 0


    def n_beautiful_days(self):

        return self._n_beautiful_days


if __name__ == '__main__':
    main()
