// Source: https://app.codility.com/programmers/lessons/1-iterations/binaryGap/

function solution(NUMBER: number): number {
    const ITERATIONS: Iterations = new Iterations(NUMBER);
    const LONGEST_BINARY_GAP: number = ITERATIONS.getLongestBinaryGap();
    return LONGEST_BINARY_GAP;
}

    class Iterations {

        #binary: string;
        #longestBinaryGap: number;

        constructor(NUMBER: number) {
            this.#binary = this.#convertNumberToBinaryString(NUMBER);
            this.#longestBinaryGap = this.#findLongestBinaryGap();
        }

            #convertNumberToBinaryString(NUMBER: number): string {
                const BINARY: string = (NUMBER >>> 0).toString(2);
                return BINARY;
            }

            #findLongestBinaryGap(): number {
                let longestBinaryGap: number = 0;

                for (let index = {'i': 0, 'j': 0, 'k': 0}; Object.values(index).includes(-1) === false;) {
                    const GAPLENGTH: number = this.#findGapLength(index);
                    longestBinaryGap = Math.max(GAPLENGTH, longestBinaryGap);
                }

                return longestBinaryGap;
            }

                #findGapLength(index: {i: number; j: number; k: number;}): number {
                    index.i = this.#binary.indexOf('1', index.j);
                    if (index.i != -1) {

                        index.j = this.#binary.indexOf('0', index.i + 1);
                        if (index.j != -1) {

                            index.k = this.#binary.indexOf('1', index.j + 1);
                            if (index.k != -1) {
                                const GAPLENGTH: number = index.k - index.j;
                                return GAPLENGTH;
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

        getLongestBinaryGap(): number {
            return this.#longestBinaryGap;
        }
    }
