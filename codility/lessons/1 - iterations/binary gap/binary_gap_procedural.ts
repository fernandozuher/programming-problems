// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

function solution(number: number): number {
    const BINARY: string = convertNumberToBinaryString(number);
    const LONGEST_BINARY_GAP: number = findLongestBinaryGap(BINARY);
    return LONGEST_BINARY_GAP;
}

    function convertNumberToBinaryString(number: number): string {
        return (number >>> 0).toString(2);
    }

    function findLongestBinaryGap(binary: string): number {
        let longestBinaryGap = 0;

        for (let index = {'i': 0, 'j': 0, 'k': 0}; Object.values(index).includes(-1) === false;) {
            const GAP_LENGTH: number = findGapLength(binary, index);
            longestBinaryGap = Math.max(GAP_LENGTH, longestBinaryGap);
        }

        return longestBinaryGap;
    }

        function findGapLength(binary: string, index: { i: number; j: number; k: number; } ): number {
            index.i = binary.indexOf('1', index.j);

            if (index.i != -1) {
                index.j = binary.indexOf('0', index.i + 1);

                if (index.j != -1) {
                    index.k = binary.indexOf('1', index.j + 1);

                    if (index.k != -1) {
                        const GAP_LENGTH: number = index.k - index.j;
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
