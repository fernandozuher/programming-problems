# Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

def main():

    LOWER_LIMIT = int(input())
    UPPER_LIMIT = int(input())

    OBJ = KaprekarNumbers(LOWER_LIMIT, UPPER_LIMIT)
    print_output(OBJ.get_kaprekar_numbers())


class KaprekarNumbers:

    def __init__(self, lower_limit, upper_limit):

        self._lower_limit = lower_limit
        self._upper_limit = upper_limit
        self._kaprekar_numbers = []

        self._find_kaprekar_numbers_in_range()
    

    def _find_kaprekar_numbers_in_range(self):

        for number in range(self._lower_limit, self._upper_limit + 1):
            POTENTIAL_KAPREKAR_NUMBER = self._calculate_potential_kaprekar_number(number)
            if number == POTENTIAL_KAPREKAR_NUMBER:
                self._kaprekar_numbers.append(number)


    def _calculate_potential_kaprekar_number(self, number):

        SQUARE_NUMBER_IN_STRING = str(pow(number, 2))
        LENGTH_OF_NUMBER_IN_STRING = len(str(number))

        LEFT_NUMBER_IN_STRING = self._get_left_number_in_string(SQUARE_NUMBER_IN_STRING, LENGTH_OF_NUMBER_IN_STRING)
        RIGHT_NUMBER_IN_STRING = self._get_right_number_in_string(SQUARE_NUMBER_IN_STRING, LENGTH_OF_NUMBER_IN_STRING)

        POTENTIAL_KAPREKAR_NUMBER = self._sumNumbersInStrings(LEFT_NUMBER_IN_STRING, RIGHT_NUMBER_IN_STRING)

        return POTENTIAL_KAPREKAR_NUMBER


    def _get_left_number_in_string(self, square_number_in_string, length_of_number_in_string):

        DIGITS_TO_SKIP = 0
        DIGITS_TO_TAKE = len(square_number_in_string) - length_of_number_in_string
        NUMBER_IN_STRING = square_number_in_string[DIGITS_TO_SKIP : DIGITS_TO_TAKE]
        return NUMBER_IN_STRING


    def _get_right_number_in_string(self, square_number_in_string, length_of_number_in_string):

        DIGITS_TO_SKIP = len(square_number_in_string) - length_of_number_in_string
        NUMBER_IN_STRING = square_number_in_string[DIGITS_TO_SKIP:]
        return NUMBER_IN_STRING


    def _sumNumbersInStrings(self, left_number_in_string, right_number_in_string):

        if len(left_number_in_string) > 0 and len(right_number_in_string) > 0:
            return int(left_number_in_string) + int(right_number_in_string)
        elif len(left_number_in_string) == 0:
            return int(right_number_in_string)
        elif len(right_number_in_string) == 0:
            return int(left_number_in_string)

        return 0


    def get_kaprekar_numbers(self):

        return self._kaprekar_numbers


def print_output(array):

    if len(array) > 0:
        print(*array, sep=" ")
    else:
        print("INVALID RANGE")


if __name__ == "__main__":
    main()
