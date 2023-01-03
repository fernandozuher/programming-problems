// Source: https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

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
    const input1: number[] = readLineAsNumberArray();
    const itemAnnaDidntConsume: number = input1[1];
    
    const costOfEachMeal: number[] = readLineAsNumberArray();
    const brianChargedAnna: number[] = readLineAsNumberArray();

    const result = new Result(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna[0]);
}

    function readLineAsNumberArray() {
        const numbers: number[] = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        private _costOfEachMeal: number[];
        private _itemAnnaDidntConsume: number;
        private _brianChargedAnna: number;
        private _brianOverchargedAnna: string;

        constructor(costOfEachMeal: number[], itemAnnaDidntConsume: number, brianChargedAnna: number) {
            this._costOfEachMeal = costOfEachMeal;
            this._itemAnnaDidntConsume = itemAnnaDidntConsume;
            this._brianChargedAnna = brianChargedAnna;
            this._brianOverchargedAnna = "";

            this._bonAppetit();
            this.printResult();
        }

            private _bonAppetit() {
                const annaCost: number = this._calculateAnnaCost();
                this._brianOverchargedAnna = this._checkIfBrianOverchargedAnna(annaCost);
            }

                private _calculateAnnaCost(): number {
                    const sum: number = this._costOfEachMeal.reduce((a, b) => a + b, 0);
                    const annaCost: number = (sum - this._costOfEachMeal[this._itemAnnaDidntConsume]) / 2;
                    return annaCost;
                }

                private _checkIfBrianOverchargedAnna(annaCost: number) {
                    if (annaCost === this._brianChargedAnna)
                        return "Bon Appetit";
                    else {
                        const brianOverchargedAnna: number = this._brianChargedAnna - annaCost;
                        return brianOverchargedAnna.toString();
                    }
                }
        
            printResult() {
                console.log(this._brianOverchargedAnna);
            }
    }
