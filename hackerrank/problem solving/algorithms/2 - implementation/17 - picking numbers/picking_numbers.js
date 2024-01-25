// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

////////////////////////////////////////////////

function main() {
    let n = +readLine();
    let array = readIntArray();
    array.sort((a, b) => a - b);

    let obj = new PickingNumbers(array);
    console.log(obj.subarrayBiggestSize());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class PickingNumbers {
        #numbers;
        #subarrayBiggestSize;

        constructor(numbers) {
            this.#numbers = numbers;
            this.#subarrayBiggestSize = 1;
            this.#pickingNumbers();
        }

            #pickingNumbers() {
                let firstReferenceNumberIndex = 0;
                let secondReferenceNumberIndex = 0;
                let subarrayCurrentSize = 1;

                for (let i = 1, n = this.#numbers.length; i < n; ++i) {
                    let difference = this.#numbers[i] - this.#numbers[firstReferenceNumberIndex];

                    switch (difference) {
                        case 0:
                            ++subarrayCurrentSize;
                            break;

                        case 1:
                            ++subarrayCurrentSize;
                            if (this.#numbers[secondReferenceNumberIndex] != this.#numbers[i]) secondReferenceNumberIndex = i;
                            break;

                        default:
                            this.#subarrayBiggestSize = this.#updateSubarrayBiggestSize(subarrayCurrentSize);
                            let update = this.#updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex);
                            firstReferenceNumberIndex = update[0];
                            secondReferenceNumberIndex = i;
                            subarrayCurrentSize = update[1];
                    }
                }
                this.#subarrayBiggestSize = this.#updateSubarrayBiggestSize(subarrayCurrentSize);
            }

                #updateSubarrayBiggestSize(subarrayCurrentSize) {
                    return Math.max(subarrayCurrentSize, this.#subarrayBiggestSize);
                }

                #updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex) {
                    let firstReferenceNumberIndex, subarrayCurrentSize;

                    if (this.#numbers[i] - this.#numbers[secondReferenceNumberIndex] === 1) {
                        firstReferenceNumberIndex = secondReferenceNumberIndex;
                        subarrayCurrentSize = i - secondReferenceNumberIndex + 1;
                    } else {
                        firstReferenceNumberIndex = i;
                        subarrayCurrentSize = 1;
                    }

                    return [firstReferenceNumberIndex, subarrayCurrentSize];
                }

        subarrayBiggestSize() {
            return this.#subarrayBiggestSize;
        }
    }
