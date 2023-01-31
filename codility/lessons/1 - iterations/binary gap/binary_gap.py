# Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

def solution(N):

    BINARY = convertNumberToBinaryString(N)
    LONGEST_BINARY_GAP = findLongestBinaryGap(BINARY)
    return LONGEST_BINARY_GAP


def convertNumberToBinaryString(N):

    BINARY = '{0:b}'.format(N);
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
    index['j'] = BINARY.find('0', index['i'] + 1)
    index['k'] = BINARY.find('1', index['j'] + 1)

    if -1 not in index.values():
        GAP_LENGTH = index['k'] - index['j']
        return GAP_LENGTH

    return 0
