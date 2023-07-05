// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

function solution(number: number): number {
    const OBJ = new BinaryGap(number);
    return OBJ.getLongestBinaryGap();
}

    class BinaryGap {
        private number: number;
        private binary: string;
        private longestBinaryGap: number;

        public constructor(number: number) {
            this.number = number;
            this.binary = "";
            this.longestBinaryGap = 0;

            this.binary = this.convertNumberToBinaryString(this.number);
            this.findLongestBinaryGap();
        }

            private convertNumberToBinaryString(number: number): string {
                return (number >>> 0).toString(2);
            }

            private findLongestBinaryGap() {
                for (let index = {'i': 0, 'j': 0, 'k': 0}; Object.values(index).includes(-1) === false;) {
                    const GAP_LENGTH: number = this.findGapLength(index);
                    this.longestBinaryGap = Math.max(GAP_LENGTH, this.longestBinaryGap);
                }
            }

                private findGapLength(index: {i: number; j: number; k: number;}): number {
                    index.i = this.binary.indexOf('1', index.j);
                    if (index.i != -1) {

                        index.j = this.binary.indexOf('0', index.i + 1);
                        if (index.j != -1) {

                            index.k = this.binary.indexOf('1', index.j + 1);
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

        public getLongestBinaryGap(): number {
            return this.longestBinaryGap;
        }
    }
