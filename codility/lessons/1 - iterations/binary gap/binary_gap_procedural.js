// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

function solution(NUMBER) {
    const BINARY = convertNumberToBinaryString(NUMBER);
    const LONGEST_BINARY_GAP = findLongestBinaryGap(BINARY);
    return LONGEST_BINARY_GAP;
}

    function convertNumberToBinaryString(NUMBER) {
        const BINARY = (NUMBER >>> 0).toString(2);
        return BINARY;
    }

    function findLongestBinaryGap(BINARY) {
        let longestBinaryGap = 0;

        for (let index = {'i': 0, 'j': 0, 'k': 0}; Object.values(index).includes(-1) === false;) {
            const GAP_LENGTH = findGapLength(BINARY, index);
            longestBinaryGap = Math.max(GAP_LENGTH, longestBinaryGap);
        }

        return longestBinaryGap;
    }

        function findGapLength(BINARY, index) {
            index.i = BINARY.indexOf('1', index.j);

            if (index.i != -1) {
                index.j = BINARY.indexOf('0', index.i + 1);

                if (index.j != -1) {
                    index.k = BINARY.indexOf('1', index.j + 1);

                    if (index.k != -1) {
                        const GAP_LENGTH = index.k - index.j;
                        return GAP_LENGTH;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
