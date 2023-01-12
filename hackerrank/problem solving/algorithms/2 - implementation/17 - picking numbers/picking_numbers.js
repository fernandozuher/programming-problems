// Source:
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    readLineAsNumberArray();

    const numbers = readLineAsNumberArray();
    numbers.sort((a, b) => a - b);

    const result = new Result(numbers);
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    class Result {
        #numbers;
        #subarrayBiggestSize;

        constructor(numbers) {
            this.#numbers = [...numbers];
            this.#subarrayBiggestSize = 1;

            this.#pickingNumbers();
            this.printResult();
        }

            #pickingNumbers() {
                let firstReferenceNumberIndex = 0;
                let secondReferenceNumberIndex = 0;
                let subarrayCurrentSize = 1;

                for (let i = 1, n = this.#numbers.length; i < n; i++) {
                    let difference = this.#numbers[i] - this.#numbers[firstReferenceNumberIndex];

                    switch (difference) {
                        case 0:
                            subarrayCurrentSize++;
                            break;

                        case 1:
                            subarrayCurrentSize++;
                            if (this.#numbers[secondReferenceNumberIndex] != this.#numbers[i])
                                secondReferenceNumberIndex = i;
                            break;

                        default:
                            this.#subarrayBiggestSize = this.#updateSubarrayBiggestSize(subarrayCurrentSize);
                            const update = this.#updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex);

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
                    }
                    else {
                        firstReferenceNumberIndex = i;
                        subarrayCurrentSize = 1;
                    }

                    const result = [firstReferenceNumberIndex, subarrayCurrentSize];
                    return result;
                }

            printResult() {
                console.log(this.#subarrayBiggestSize);
            }
    }
