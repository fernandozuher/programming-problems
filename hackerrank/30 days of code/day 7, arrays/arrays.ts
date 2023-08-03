// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

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
    const _N: number = +readLine();
    const ARRAY: number[] = readLine().split(' ').map(Number);
    // Not available in the current version of TS used in HackerRank
    // ARRAY.findLast(element => {process.stdout.write(`${element} `)});
    for (let i = ARRAY.length - 1; i >= 0; i--)
        process.stdout.write(`${ARRAY[i]} `);
}
