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
    let _n: number = +readLine();
    let array: number[] = readLine().split(' ').map(Number);
    // Not available in the current version of TS used in HackerRank
    // array.findLast(x => {process.stdout.write(`${x} `)});
    for (let i = array.length; i--;)
        process.stdout.write(`${array[i]} `);
}
