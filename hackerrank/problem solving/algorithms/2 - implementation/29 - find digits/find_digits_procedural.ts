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

    for (let i = 0; i < N_TEST_CASES; i++) {
        const NUMBER: number = readANumber();
        output[i] = findNumberDivisorsQuantity(NUMBER);
    }

    printOutput(output);
}

    function readANumber(): number {
        const NUMBER: number = +readLine();
        return NUMBER;
    }

    function findNumberDivisorsQuantity(inputNumber: number): number {
        let divisors: number = 0;

        for (let currentNumber: number = inputNumber; currentNumber != 0; currentNumber = removeLastDigitOfNumber(currentNumber)) {
            const DIVISOR: number = getLastDigitOfNumber(currentNumber);
            if (isNumberEvenlyDividedByDivisor(inputNumber, DIVISOR))
                divisors++;
        }

        return divisors;
    }

        function getLastDigitOfNumber(inputNumber: number): number {
            return inputNumber % 10;
        }

        function isNumberEvenlyDividedByDivisor(inputNumber: number, divisor: number): boolean {
            return divisor != 0 && inputNumber % divisor == 0;
        }

        function removeLastDigitOfNumber(inputNumber: number): number {
            return Math.trunc(inputNumber / 10);
        }

    function printOutput(array: Array<number>) {
        array.forEach(number => console.log(number));
    }
