// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

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
    const N_TEST_CASES: number = +readLine();
    const OUTPUT: Array<number> = new Array(N_TEST_CASES).fill(0);

    for (let i in OUTPUT) {
        const [BEGIN, END]: Array<number> = readAnArray();
        const OBJ: SherlockAndSquares = new SherlockAndSquares(BEGIN, END);
        OUTPUT[i] = OBJ.getQuantityOfSquareIntegers();
    }

    printArray(OUTPUT);
}

    function readAnArray(): Array<number> {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function printArray(array: Array<number>) {
        array.forEach(element => console.log(element));
    }

    class SherlockAndSquares {
        private _begin: number;
        private _end: number;
        private _quantityOfSquareIntegers: number;

        public constructor(begin: number, end: number) {
            this._begin = begin;
            this._end = end;
            this._quantityOfSquareIntegers = 0;

            this._calculateNumberOfSquareIntegersInRange();
        }

            private _calculateNumberOfSquareIntegersInRange() {
                const FIRST_SQUARE_INTEGER: number = this._findFirstSquareIntegerFromBeginNumber();
                for (let number = FIRST_SQUARE_INTEGER; this._isPowerOf2OfNumberLessThanOrEqualToEndNumber(number); number++)
                   this._quantityOfSquareIntegers++;
            }

                private _findFirstSquareIntegerFromBeginNumber(): number {
                    const SQUARE_ROOT_NUMBER: number = Math.sqrt(this._begin);
                    const SQUARE_INTEGER: number = this._getSquareIntegerFromNumber(SQUARE_ROOT_NUMBER);
                    return SQUARE_INTEGER;
                }

                    private _getSquareIntegerFromNumber(number: number): number {
                        const INTEGER_PART: number = Math.trunc(number);
                        return number === INTEGER_PART ? INTEGER_PART : INTEGER_PART + 1;
                    }

                private _isPowerOf2OfNumberLessThanOrEqualToEndNumber(number: number): boolean {
                    return Math.pow(number, 2) <= this._end;
                }

        public getQuantityOfSquareIntegers(): number {
            return this._quantityOfSquareIntegers;
        }
    }
