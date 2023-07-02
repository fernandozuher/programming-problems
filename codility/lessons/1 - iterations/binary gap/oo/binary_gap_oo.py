# Source: https://app.codility.com/programmers/lessons/1-iterations/binaryGap/

def solution(NUMBER):

    ITERATIONS = Iterations(NUMBER)
    LONGEST_BINARY_GAP = ITERATIONS.getLongestBinaryGap()
    return LONGEST_BINARY_GAP


class Iterations:

    def __init__(self, NUMBER):

        self.__binary = self.__convertNumberToBinaryString(NUMBER)
        self.__longestBinaryGap = self.__findLongestBinaryGap()


    def __convertNumberToBinaryString(self, NUMBER):

        BINARY = '{0:b}'.format(NUMBER)
        return BINARY


    def __findLongestBinaryGap(self):

        longestBinaryGap = 0
        index = {'i': 0, 'j': 0, 'k': 0}

        while -1 not in index.values():
            GAP_LENGTH = self.__findGapLength(index)
            longestBinaryGap = max(GAP_LENGTH, longestBinaryGap)

        return longestBinaryGap


    def __findGapLength(self, index):

        index['i'] = self.__binary.find('1', index['j'])

        if index['i'] != -1:
            index['j'] = self.__binary.find('0', index['i'] + 1)

            if index['j'] != -1:
                index['k'] = self.__binary.find('1', index['j'] + 1)

                if index['k'] != -1:
                    GAP_LENGTH = index['k'] - index['j']
                    return GAP_LENGTH
                else:
                    return 0
            else:
                return 0
        else:
            return 0


    def getLongestBinaryGap(self):

        return self.__longestBinaryGap
