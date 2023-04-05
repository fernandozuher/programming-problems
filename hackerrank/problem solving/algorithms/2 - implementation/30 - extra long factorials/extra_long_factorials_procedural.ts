// Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

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
    const NUMBER: number = +readLine();
    const FACTORIAL: bigint = calculateFactorialOf(NUMBER);
    console.log(FACTORIAL.toString());
}

    function calculateFactorialOf(number: number): bigint {
        let factorial: bigint = BigInt(1);
        for (let i = BigInt(2); i <= number; i++)
            factorial *= i;
        return factorial;
    }
