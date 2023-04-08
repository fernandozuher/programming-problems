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
        OUTPUT[i] = calculateNumberOfSquareIntegersInRange(BEGIN, END);
    }

    printArray(OUTPUT);
}

    function readAnArray(): Array<number> {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function calculateNumberOfSquareIntegersInRange(begin: number, end: number): number {
        let squares: number = 0;
        for (let number: number = findFirstSquareIntegerFromNumber(begin); isPowerOf2OfNumberLessThanOrEqualToLimit(number, end); number++)
            squares++;
        return squares;
    }

        function findFirstSquareIntegerFromNumber(number: number): number {
            const SQUARE_ROOT_NUMBER: number = Math.sqrt(number);
            const SQUARE_INTEGER = getSquareIntegerFromNumber(SQUARE_ROOT_NUMBER);
            return SQUARE_INTEGER;
        }

            function getSquareIntegerFromNumber(number: number): number {
                const INTEGER_PART: number = Math.trunc(number);
                return number === INTEGER_PART ? INTEGER_PART : INTEGER_PART + 1;
            }

        function isPowerOf2OfNumberLessThanOrEqualToLimit(number: number, limit: number): boolean {
            return Math.pow(number, 2) <= limit;
        }

    function printArray(array: Array<number>) {
        array.forEach(element => console.log(element));
    }
