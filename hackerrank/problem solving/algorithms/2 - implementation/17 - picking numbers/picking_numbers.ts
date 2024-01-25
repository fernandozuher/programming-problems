// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

////////////////////////////////////////////////

function main() {
    let n: number = +readLine();
    let array: number[] = readIntArray();
    array.sort((a, b) => a - b);

    let obj = new PickingNumbers(array);
    console.log(obj.subarrayBiggestSize());
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class PickingNumbers {
        private numbers: number[];
        private subarrayBiggestLength: number;

        constructor(numbers: number[]) {
            this.numbers = numbers;
            this.subarrayBiggestLength = 1;
            this.pickingNumbers();
        }

            private pickingNumbers() {
                let firstReferenceNumberIndex = 0;
                let secondReferenceNumberIndex = 0;
                let subarrayCurrentSize = 1;

                for (let i = 1, n = this.numbers.length; i < n; ++i) {
                    let difference: number = this.numbers[i] - this.numbers[firstReferenceNumberIndex];

                    switch (difference) {
                        case 0:
                            ++subarrayCurrentSize;
                            break;

                        case 1:
                            ++subarrayCurrentSize;
                            if (this.numbers[secondReferenceNumberIndex] != this.numbers[i])
                                secondReferenceNumberIndex = i;
                            break;

                        default:
                            this.subarrayBiggestLength = this.updateSubarrayBiggestSize(subarrayCurrentSize);
                            let update: number[] = this.updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex);

                            firstReferenceNumberIndex = update[0];
                            secondReferenceNumberIndex = i;
                            subarrayCurrentSize = update[1];
                    }
                }

                this.subarrayBiggestLength = this.updateSubarrayBiggestSize(subarrayCurrentSize);
            }

                private updateSubarrayBiggestSize(subarrayCurrentSize: number): number {
                    return Math.max(subarrayCurrentSize, this.subarrayBiggestLength);
                }

                private updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i: number, secondReferenceNumberIndex: number): number[] {
                    let firstReferenceNumberIndex, subarrayCurrentSize: number;

                    if (this.numbers[i] - this.numbers[secondReferenceNumberIndex] === 1) {
                        firstReferenceNumberIndex = secondReferenceNumberIndex;
                        subarrayCurrentSize = i - secondReferenceNumberIndex + 1;
                    }
                    else {
                        firstReferenceNumberIndex = i;
                        subarrayCurrentSize = 1;
                    }

                    return [firstReferenceNumberIndex, subarrayCurrentSize];
                }

        subarrayBiggestSize(): number {
            return this.subarrayBiggestLength;
        }
    }
