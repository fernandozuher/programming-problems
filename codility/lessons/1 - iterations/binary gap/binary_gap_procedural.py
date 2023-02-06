# Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

def solution(NUMBER):

    BINARY = convertNumberToBinaryString(NUMBER)
    LONGEST_BINARY_GAP = findLongestBinaryGap(BINARY)
    return LONGEST_BINARY_GAP


def convertNumberToBinaryString(NUMBER):

    BINARY = '{0:b}'.format(NUMBER);
    return BINARY


def findLongestBinaryGap(BINARY):

    longestBinaryGap = 0
    index = {'i': 0, 'j': 0, 'k': 0}

    while -1 not in index.values():
        GAP_LENGTH = findGapLength(BINARY, index)
        longestBinaryGap = max(GAP_LENGTH, longestBinaryGap)
    
    return longestBinaryGap


def findGapLength(BINARY, index):
    
    index['i'] = BINARY.find('1', index['j'])

    if index['i'] != -1:
        index['j'] = BINARY.find('0', index['i'] + 1)

        if index['j'] != -1:
            index['k'] = BINARY.find('1', index['j'] + 1)

            if index['k'] != -1:
                GAP_LENGTH = index['k'] - index['j']
                return GAP_LENGTH
            else:
                return 0
        else:
            return 0
    else:
        return 0
