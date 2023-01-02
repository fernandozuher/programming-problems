// Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

'use strict';
const fs = require('fs');
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
    const input1 = readLineAsNumberArray();
    const k = input1[1];
    let numbers = readLineAsNumberArray();

    numbers.sort((a, b) => a - b);

    const result = new Result(numbers, k);
}

    function readLineAsNumberArray() {
        const numbers = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        #numbers;
        #k;
        #nDivisibleSumPairs;

        constructor(numbers, k) {
            this.#numbers = [...numbers];
            this.#k = k;
            this.#nDivisibleSumPairs = 0;

            this.#divisibleSumPairs();
            this.printResult();
        }

            #divisibleSumPairs() {
                for (let i = 0, n1 = this.#numbers.length - 1; i < n1; i++)
                    for (let j = i + 1; j < this.#numbers.length; j++)
                        if (this.#numbers[i] <= this.#numbers[j] && !((this.#numbers[i] + this.#numbers[j]) % this.#k))
                            this.#nDivisibleSumPairs++;
            }
        
            printResult() {
                console.log(this.#nDivisibleSumPairs);
            }
    }
