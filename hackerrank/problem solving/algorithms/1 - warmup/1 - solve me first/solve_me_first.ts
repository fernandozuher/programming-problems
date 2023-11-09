// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

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
    let num1: number = +readLine();
    let num2: number = +readLine();
    console.log(solveMeFirst(num1, num2));
}

    function solveMeFirst(a: number, b: number): number {
        return a + b;
    }
