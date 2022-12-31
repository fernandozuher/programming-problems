// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

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
    readLineAsNumberArray();
    const chocolateSquares: number[] = readLineAsNumberArray();
    const dayMonth: number[] = readLineAsNumberArray();

    const result = new Result(chocolateSquares, dayMonth);
}

    function readLineAsNumberArray() {
        const numbers: number[] = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        private _chocolateSquares: number[];
        private _day: number;
        private _month: number;
        private _waysBarCanBeDivided: number;

        constructor(chocolateSquares: number[], dayMonth: number[]) {
            this._chocolateSquares = [...chocolateSquares];
            this._day = dayMonth[0];
            this._month = dayMonth[1];
            this._waysBarCanBeDivided = 0;

            this._birthday();
            this.printResult();
        }

            private _birthday() {
                for (let i = 0, n1 = this._chocolateSquares.length - this._month + 1; i < n1; i++) {
                    let sum = 0;
                    for (let j = i, n2 = i + this._month; j < n2; sum += this._chocolateSquares[j++]);
                    if (sum === this._day)
                        this._waysBarCanBeDivided++;
                }
            }
        
            printResult() {
                console.log(this._waysBarCanBeDivided);
            }
    }
