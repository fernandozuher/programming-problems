// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

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

class Result {
    private _scores: number[];
    private _breakingMostPointsRecords: number;
    private _breakingLeastPointsRecords: number;

    constructor(setA: number[]) {
        this._scores = [...setA];
        this._breakingMostPointsRecords = 0;
        this._breakingLeastPointsRecords = 0;
        this._breakingRecords();
        this.printResult();
    }

        private _breakingRecords() {
            let mostPoints = this._scores[0];
            let leastPoints = this._scores[0];

            for (let score of this._scores)
                if (score > mostPoints) {
                    mostPoints = score;
                    this._breakingMostPointsRecords++;
                } else if (score < leastPoints) {
                    leastPoints = score;
                    this._breakingLeastPointsRecords++;
                }
        }
    
        printResult() {
            console.log(`${this._breakingMostPointsRecords} ${this._breakingLeastPointsRecords}`);
        }
}

function readLineAsNumericArray() {
    const numbers: number[] = readLine().split(" ").map(Number);
    return numbers;
}

function main() {
    readLineAsNumericArray();
    const setA: number[] = readLineAsNumericArray();
    const result = new Result(setA);
}
