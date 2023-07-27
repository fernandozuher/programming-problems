// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true

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
    const I: number = 4;
    const D: number = 4.0;
    const S: string = "HackerRank ";

    const I2: number = parseInt(readLine());
    const D2: number = parseFloat(readLine());
    const S2: string = readLine();

    console.log(I + I2);
    console.log((D + D2).toFixed(1));
    console.log(S + S2);
}
