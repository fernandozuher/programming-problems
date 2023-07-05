# Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

def solution(number):

    OBJ = BinaryGap(number)
    return OBJ.get_longest_binary_gap()


class BinaryGap:

    def __init__(self, number):

        self._number = number
        self._binary = ""
        self._longest_binary_gap = 0

        self._binary = self._convert_number_to_binary_string(self._number)
        self._find_longest_binary_gap()


    def _convert_number_to_binary_string(self, number):

        return '{0:b}'.format(number)


    def _find_longest_binary_gap(self):

        index = {'i': 0, 'j': 0, 'k': 0}

        while -1 not in index.values():
            GAP_LENGTH = self._find_gap_length(index)
            self._longest_binary_gap = max(GAP_LENGTH, self._longest_binary_gap)


    def _find_gap_length(self, index):

        index['i'] = self._binary.find('1', index['j'])

        if index['i'] != -1:
            index['j'] = self._binary.find('0', index['i'] + 1)

            if index['j'] != -1:
                index['k'] = self._binary.find('1', index['j'] + 1)

                if index['k'] != -1:
                    GAP_LENGTH = index['k'] - index['j']
                    return GAP_LENGTH
                else:
                    return 0
            else:
                return 0
        else:
            return 0


    def get_longest_binary_gap(self):

        return self._longest_binary_gap
