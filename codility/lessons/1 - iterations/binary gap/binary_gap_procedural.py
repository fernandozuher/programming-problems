# Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

def solution(number):

    BINARY = convert_number_to_binary_string(number)
    LONGEST_BINARY_GAP = find_longest_binary_gap(BINARY)
    return LONGEST_BINARY_GAP


def convert_number_to_binary_string(number):

    return '{0:b}'.format(number)


def find_longest_binary_gap(binary):

    longest_binary_gap = 0
    index = {'i': 0, 'j': 0, 'k': 0}

    while -1 not in index.values():
        GAP_LENGTH = find_gap_length(binary, index)
        longest_binary_gap = max(GAP_LENGTH, longest_binary_gap)
    
    return longest_binary_gap


def find_gap_length(binary, index):
    
    index['i'] = binary.find('1', index['j'])

    if index['i'] != -1:
        index['j'] = binary.find('0', index['i'] + 1)

        if index['j'] != -1:
            index['k'] = binary.find('1', index['j'] + 1)

            if index['k'] != -1:
                GAP_LENGTH = index['k'] - index['j']
                return GAP_LENGTH
            else:
                return 0
        else:
            return 0
    else:
        return 0
