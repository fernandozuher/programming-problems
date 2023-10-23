# https://www.hackerrank.com/challenges/30-testing/problem?isFullScreen=true

def main():

    test_with_empty_array()
    test_with_unique_values()
    test_with_exacty_two_different_minimums()
    print("OK")


def test_with_empty_array():

    try:
        seq = TestDataEmptyArray.get_array()
        result = minimum_index(seq)
    except ValueError as e:
        pass
    else:
        assert False


def minimum_index(seq):

    if len(seq) == 0:
        raise ValueError("Cannot get the minimum value index from an empty sequence")

    min_idx = 0
    for i in range(1, len(seq)):
        if seq[i] < seq[min_idx]:
            min_idx = i

    return min_idx


def test_with_unique_values():

    seq = TestDataUniqueValues.get_array()
    assert len(seq) >= 2

    assert len(list(set(seq))) == len(seq)

    expected_result = TestDataUniqueValues.get_expected_result()
    result = minimum_index(seq)
    assert result == expected_result


def test_with_exacty_two_different_minimums():

    seq = TestDataExactlyTwoDifferentMinimums.get_array()
    assert len(seq) >= 2
    tmp = sorted(seq)
    assert tmp[0] == tmp[1] and (len(tmp) == 2 or tmp[1] < tmp[2])

    expected_result = TestDataExactlyTwoDifferentMinimums.get_expected_result()
    result = minimum_index(seq)
    assert result == expected_result


class TestDataEmptyArray:

    @staticmethod
    def get_array():

        return []


class TestDataUniqueValues:

    @staticmethod
    def get_array():

        return [2, 1]


    @staticmethod
    def get_expected_result():

        return 1


class TestDataExactlyTwoDifferentMinimums:

    @staticmethod
    def get_array():

        return [1, 2, 1]


    @staticmethod
    def get_expected_result():

        return 0


if __name__ == '__main__':
    main()
