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
    
    private _setA: number[];
    private _setB: number[];
    private _potentialFactors: number[];
    private _totalFactors: number;
    
    private _findFactors() {
        this._findNumbersDivisibleBySetA();
        this._findFactorsOfSetB();
        this._countFactors();
    }

        private _findNumbersDivisibleBySetA() {
            let lastElementOfSetA: number = this._setA[this._setA.length - 1];

            for (let potentialFactor = lastElementOfSetA; potentialFactor <=this._setB[0]; potentialFactor += lastElementOfSetA) {
                let isARealPotentialFactor = true;
                for (let elementA of this._setA)
                    if (potentialFactor % elementA) {
                        isARealPotentialFactor = false;
                        break;
                    }
                if (isARealPotentialFactor)
                    this._potentialFactors.push(potentialFactor);
            }
        }

        private _findFactorsOfSetB() {
            for (const elementB of this._setB)
                for (const [i, potentialFactor] of this._potentialFactors.entries())
                    if (potentialFactor && elementB % potentialFactor)
                        this._potentialFactors[i] = 0;
        }

        private _countFactors() {
            this._totalFactors = this._potentialFactors.reduce((previousResult, item) => item != 0 ? ++previousResult : previousResult, 0);
        }

    constructor(setA: number[], setB: number[]) {
        this._setA = [...setA];
        this._setB = [...setB];

        this._potentialFactors = new Array();
        this._totalFactors = 0;
        this._findFactors();
        this.printResult();
    }
    
        printResult() {
            console.log(this._totalFactors);
        }
}

function readLineAsNumericArray() {
    const numbers: number[] = readLine().split(" ").map(Number);
    return numbers;
}

function main() {
    readLineAsNumericArray();
    const setA: number[] = readLineAsNumericArray();
    const setB: number[] = readLineAsNumericArray();
    const result = new Result(setA, setB);
}