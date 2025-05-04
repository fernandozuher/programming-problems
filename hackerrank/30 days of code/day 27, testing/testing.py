# https://www.hackerrank.com/challenges/30-testing/problem?isFullScreen=true

import unittest


class MinimumIndexTests(unittest.TestCase):
    def test_empty_array(self):
        numbers = []
        with self.assertRaises(ValueError):
            minimum_index_of_smallest_element(numbers)

    def test_unique_values(self):
        numbers = [2, 1]
        index = minimum_index_of_smallest_element(numbers)
        self.assertEqual(index, 1)
        self.assertEqual(len(set(numbers)), len(numbers), "Elements are not unique.")

    def test_two_minimum_values(self):
        numbers = [1, 2, 1]
        index = minimum_index_of_smallest_element(numbers)
        self.assertEqual(index, 0)
        self.assertEqual(numbers.count(min(numbers)), 2,
                         "There should be exactly two occurrences of the minimum value.")


def minimum_index_of_smallest_element(numbers):
    if not numbers:
        raise ValueError("Cannot get the minimum value index from an empty sequence.")
    return numbers.index(min(numbers))


if __name__ == '__main__':
    unittest.main()
