// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

function solution(number) {
    const OBJ = new BinaryGap(number);
    return OBJ.getLongestBinaryGap();
}

    class BinaryGap {
        #number;
        #binary;
        #longestBinaryGap;

        constructor(number) {
            this.#number = number;
            this.#binary = "";
            this.#longestBinaryGap = 0;

            this.#binary = this.#convertNumberToBinaryString(this.#number);
            this.#findLongestBinaryGap();
        }

            #convertNumberToBinaryString(number) {
                return (number >>> 0).toString(2);
            }

            #findLongestBinaryGap() {
                for (let index = {'i': 0, 'j': 0, 'k': 0}; Object.values(index).includes(-1) === false;) {
                    const GAP_LENGTH = this.#findGapLength(index);
                    this.#longestBinaryGap = Math.max(GAP_LENGTH, this.#longestBinaryGap);
                }
            }

                #findGapLength(index) {
                    index.i = this.#binary.indexOf('1', index.j);
                    if (index.i != -1) {

                        index.j = this.#binary.indexOf('0', index.i + 1);
                        if (index.j != -1) {

                            index.k = this.#binary.indexOf('1', index.j + 1);
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

        getLongestBinaryGap() {
            return this.#longestBinaryGap;
        }
    }
