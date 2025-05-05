# https://www.hackerrank.com/challenges/30-testing/problem?isFullScreen=true

import unittest


class MinimumIndexTests(unittest.TestCase):

    def test_empty_numbers(self):
        numbers = []
        with self.assertRaises(ValueError):
            find_index_of_minimum(numbers)

    def unique_values_test(self):
        numbers = [2, 1]
        index = find_index_of_minimum(numbers)
        self.assertEqual(index, 1)
        self.assertEqual(len(set(numbers)), len(numbers), "Elements are not unique.")

    def duplicate_minimum_value_test(self):
        numbers = [1, 2, 1]
        index = find_index_of_minimum(numbers)
        self.assertEqual(index, 0)
        self.assertEqual(numbers.count(min(numbers)), 2,
                         "There should be exactly two occurrences of the minimum value.")


def find_index_of_minimum(numbers):
    if not numbers:
        raise ValueError("Cannot get the minimum value index from an empty sequence.")
    return numbers.index(min(numbers))


if __name__ == '__main__':
    unittest.main()
