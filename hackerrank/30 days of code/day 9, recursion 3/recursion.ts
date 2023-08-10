// https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

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
    const N: number = +readLine();
    console.log(factorial(N));
}

    function factorial(n: number): number {
        return n == 1 ? 1 : n * factorial(n - 1);
    }
