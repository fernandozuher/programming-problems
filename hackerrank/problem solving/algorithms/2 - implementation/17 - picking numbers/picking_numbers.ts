// Source:

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


function main() {
    readLineAsNumberArray();

    const numbers: number[] = readLineAsNumberArray();
    numbers.sort((a, b) => a - b);

    const result = new Result(numbers);
}

    function readLineAsNumberArray() {
        const inputLine: number[] = readLine().split(" ").map(Number);
        return inputLine;
    }

    class Result {
        private _numbers: number[];
        private _subarrayBiggestSize: number;

        constructor(numbers: number[]) {
            this._numbers = [...numbers];
            this._subarrayBiggestSize = 1;

            this._pickingNumbers();
            this.printResult();
        }

            private _pickingNumbers() {
                let firstReferenceNumberIndex = 0;
                let secondReferenceNumberIndex = 0;
                let subarrayCurrentSize = 1;

                for (let i = 1, n = this._numbers.length; i < n; i++) {
                    let difference: number = this._numbers[i] - this._numbers[firstReferenceNumberIndex];

                    switch (difference) {
                        case 0:
                            subarrayCurrentSize++;
                            break;

                        case 1:
                            subarrayCurrentSize++;
                            if (this._numbers[secondReferenceNumberIndex] != this._numbers[i])
                                secondReferenceNumberIndex = i;
                            break;

                        default:
                            this._subarrayBiggestSize = this._updateSubarrayBiggestSize(subarrayCurrentSize);
                            const update: number[] = this._updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex);

                            firstReferenceNumberIndex = update[0];
                            secondReferenceNumberIndex = i;
                            subarrayCurrentSize = update[1];
                    }
                }

                this._subarrayBiggestSize = this._updateSubarrayBiggestSize(subarrayCurrentSize);
            }

                private _updateSubarrayBiggestSize(subarrayCurrentSize: number): number {
                    return Math.max(subarrayCurrentSize, this._subarrayBiggestSize);
                }

                private _updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i: number, secondReferenceNumberIndex: number): number[] {
                    let firstReferenceNumberIndex, subarrayCurrentSize: number;

                    if (this._numbers[i] - this._numbers[secondReferenceNumberIndex] === 1) {
                        firstReferenceNumberIndex = secondReferenceNumberIndex;
                        subarrayCurrentSize = i - secondReferenceNumberIndex + 1;
                    }
                    else {
                        firstReferenceNumberIndex = i;
                        subarrayCurrentSize = 1;
                    }

                    const result = [firstReferenceNumberIndex, subarrayCurrentSize];
                    return result;
                }

            printResult() {
                console.log(this._subarrayBiggestSize);
            }
    }
