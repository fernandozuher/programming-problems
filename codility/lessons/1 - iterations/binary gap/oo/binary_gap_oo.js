// Source: https://app.codility.com/programmers/lessons/1-iterations/binaryGap/

function solution(NUMBER) {
    const ITERATIONS = new Iterations(NUMBER);
    const LONGEST_BINARY_GAP = ITERATIONS.getLongestBinaryGap();
    return LONGEST_BINARY_GAP;
}

    class Iterations {

        #binary;
        #longestBinaryGap;

        constructor(NUMBER) {
            this.#binary = this.#convertNumberToBinaryString(NUMBER);
            this.#longestBinaryGap = this.#findLongestBinaryGap();
        }

            #convertNumberToBinaryString(NUMBER) {
                const BINARY = (NUMBER >>> 0).toString(2);
                return BINARY;
            }

            #findLongestBinaryGap() {
                let longestBinaryGap = 0;

                for (let index = {'i': 0, 'j': 0, 'k': 0}; Object.values(index).includes(-1) === false;) {
                    const GAPLENGTH = this.#findGapLength(index);
                    longestBinaryGap = Math.max(GAPLENGTH, longestBinaryGap);
                }

                return longestBinaryGap;
            }

                #findGapLength(index) {
                    index.i = this.#binary.indexOf('1', index.j);
                    if (index.i != -1) {

                        index.j = this.#binary.indexOf('0', index.i + 1);
                        if (index.j != -1) {

                            index.k = this.#binary.indexOf('1', index.j + 1);
                            if (index.k != -1) {
                                const GAPLENGTH = index.k - index.j;
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

        getLongestBinaryGap() {
            return this.#longestBinaryGap;
        }
    }
