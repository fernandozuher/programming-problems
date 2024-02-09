# https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main():

    n = int(input())
    n_number_divisors = [None] * n

    for i in range(n):
        number = int(input())
        obj = FindDigits(number)
        n_number_divisors[i] = obj.divisors()

    print(*n_number_divisors, sep='\n')


class FindDigits:

    def __init__(self, number):

        self._number = number
        self._divisors = 0
        self._find_number_divisors_quantity()


    def _find_number_divisors_quantity(self):

        current_number = self._number

        while current_number != 0:
            divisor = self._get_last_digit_of_number(current_number)

            if self._is_number_evenly_divided_by_divisor(divisor):
                self._divisors += 1

            current_number = self._remove_last_digit_of_number(current_number)


    def _get_last_digit_of_number(self, number):

        return int(number % 10)


    def _is_number_evenly_divided_by_divisor(self, divisor):

        return divisor != 0 and self._number % divisor == 0


    def _remove_last_digit_of_number(self, number):

        return int(number / 10)


    def divisors(self):

        return self._divisors;


if __name__ == '__main__':
    main()
