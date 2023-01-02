// Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

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
    const year: number[] = readLineAsNumberArray();

    const result = new Result(year[0]);
}

    function readLineAsNumberArray() {
        const numbers: number[] = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        private _year: number;
        private _date: string;

        constructor(year: number) {
            this._year = year;
            this._date = "";

            this._dayOfProgrammer();
            this.printResult();
        }

            private _dayOfProgrammer() {
                if (this._year != 1918) {
                    const isLeap = this._year > 1918 ? this._isLeapGregorianYear() : this._isLeapJulianYear();
                    this._date = isLeap ? "12.09." : "13.09.";
                }
                else
                    this._date = "26.09.";

                this._date += this._year.toString();
            }

                private _isLeapGregorianYear() {
                    return !(this._year % 400) || (!(this._year % 4) && this._year % 100);
                }

                private _isLeapJulianYear() {
                    return !(this._year % 4);
                }
        
            printResult() {
                console.log(this._date);
            }
    }
