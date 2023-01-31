// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

function solution(N: number): number {
    const BINARY: string = convertNumberToBinaryString(N);
    const LONGEST_BINARY_GAP: number = findLongestBinaryGap(BINARY);
    return LONGEST_BINARY_GAP;
}

    function convertNumberToBinaryString(N: number): string {
        const BINARY: string = (N >>> 0).toString(2);
        return BINARY;
    }

    function findLongestBinaryGap(BINARY: string): number {
        let longestBinaryGap = 0;

        for (let index = {'i': 0, 'j': 0, 'k': 0}; Object.values(index).includes(-1) === false;) {
            const GAP_LENGTH: number = findGapLength(BINARY, index);
            longestBinaryGap = Math.max(GAP_LENGTH, longestBinaryGap);
        }

        return longestBinaryGap;
    }

        function findGapLength(BINARY: string, index: { i: number; j: number; k: number; } ): number {
            index.i = BINARY.indexOf('1', index.j);
            index.j = BINARY.indexOf('0', index.i + 1);
            index.k = BINARY.indexOf('1', index.j + 1);

            if (Object.values(index).includes(-1) === false) {
                const GAP_LENGTH: number = index.k - index.j;
                return GAP_LENGTH;
            }

            return 0;
        }
