// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    let n: number = +readLine();
    let output: number[] = new Array(n).fill(0);

    for (let i in output) {
        let [begin, end]: number[] = readIntArray();
        let obj = new SherlockAndSquares(begin, end);
        output[i] = obj.squareIntegers();
    }

    output.forEach(x => console.log(x));
}

    function readIntArray(): number[] {
        return readLine().split(" ").map(Number);
    }

    class SherlockAndSquares {
        private begin: number;
        private end: number;
        private nSquareIntegers: number;

        constructor(begin: number, end: number) {
            this.begin = begin;
            this.end = end;
            this.nSquareIntegers = 0;
            this.calculateQuantityOfSquareIntegersInRange();
        }

            private calculateQuantityOfSquareIntegersInRange() {
                let firstSquareInteger = this.findFirstSquareInteger();
                for (let number = firstSquareInteger; this.isPowerOf2LessThanOrEqualToLimit(number); ++number)
                   ++this.nSquareIntegers;
            }

                private findFirstSquareInteger(): number {
                    let squareRoot = Math.sqrt(this.begin);
                    let integerPart = Math.trunc(squareRoot);
                    return squareRoot === integerPart ? integerPart : integerPart + 1;
                }

                private isPowerOf2LessThanOrEqualToLimit(x: number): boolean {
                    return Math.pow(x, 2) <= this.end;
                }

        squareIntegers(): number {
            return this.nSquareIntegers;
        }
    }
