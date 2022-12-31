// Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

'use strict';

import { WriteStream, createWriteStream } from "fs";
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
        private _numbers: number[];
        private _k: number;
        private _nDivisibleSumPairs: number;

        constructor(numbers: number[], k: number) {
            this._numbers = [...numbers];
            this._k = k;
            this._nDivisibleSumPairs = 0;

            this._divisibleSumPairs();
            this.printResult();
        }

            private _divisibleSumPairs() {
                for (let i = 0, n1 = this._numbers.length - 1; i < n1; i++)
                    for (let j = i + 1; j < this._numbers.length; j++)
                        if (this._numbers[i] <= this._numbers[j] && !((this._numbers[i] + this._numbers[j]) % this._k))
                            this._nDivisibleSumPairs++;
            }
        
            printResult() {
                console.log(this._nDivisibleSumPairs);
            }
    }
