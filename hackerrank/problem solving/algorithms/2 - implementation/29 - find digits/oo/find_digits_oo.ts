// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

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
    const N_TEST_CASES: number = readANumber();
    const output: Array<number> = new Array(N_TEST_CASES).fill(0);

    for (let i: number = 0; i < N_TEST_CASES; i++) {
        const NUMBER: number = readANumber();
        const OBJ: FindDigits = new FindDigits(NUMBER);
        output[i] = OBJ.getDivisors();
    }

    printOutput(output);
}

    function readANumber(): number {
        const NUMBER: number = +readLine();
        return NUMBER;
    }

    function printOutput(array: Array<number>) {
        array.forEach(number => console.log(number));
    }

    class FindDigits {
        private _number: number;
        private _divisors: number;

        constructor(number: number) {
            this._number = number;
            this._divisors = 0;
            this._findNumberDivisorsQuantity();
        }

            private _findNumberDivisorsQuantity() {
                for (let currentNumber: number = this._number; currentNumber != 0; currentNumber = this._removeLastDigitOfNumber(currentNumber)) {
                    const DIVISOR: number = this._getLastDigitOfNumber(currentNumber);
                    if (this._isNumberEvenlyDividedByDivisor(DIVISOR))
                        this._divisors++;
                }
            }

                private _getLastDigitOfNumber(number: number) {
                    return number % 10;
                }

                private _isNumberEvenlyDividedByDivisor(divisor: number) {
                    return divisor != 0 && this._number % divisor == 0;
                }

                private _removeLastDigitOfNumber(number: number) {
                    return Math.trunc(number / 10);
                }

        public getDivisors() {
            return this._divisors;
        }
    }
