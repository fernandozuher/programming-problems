// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

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
    let nNumberDivisors: number[] = new Array(n).fill(0);

    for (let i = 0; i < n; ++i) {
        let number: number = +readLine();
        let obj = new FindDigits(number);
        nNumberDivisors[i] = obj.divisors();
    }

    nNumberDivisors.forEach(x => console.log(x));
}

    class FindDigits {
        private number: number;
        private nDivisors: number;

        constructor(number: number) {
            this.number = number;
            this.nDivisors = 0;
            this.findNumberDivisorsQuantity();
        }

            private findNumberDivisorsQuantity() {
                for (let currentNumber = this.number; currentNumber != 0; currentNumber = this.removeLastDigitOfNumber(currentNumber)) {
                    let divisor = this.getLastDigitOfNumber(currentNumber);
                    if (this.isNumberEvenlyDividedByDivisor(divisor))
                        ++this.nDivisors;
                }
            }

                private getLastDigitOfNumber(number: number): number {
                    return number % 10;
                }

                private isNumberEvenlyDividedByDivisor(divisor: number): boolean {
                    return divisor != 0 && this.number % divisor == 0;
                }

                private removeLastDigitOfNumber(number: number): number {
                    return Math.trunc(number / 10);
                }

        public divisors(): number {
            return this.nDivisors;
        }
    }
