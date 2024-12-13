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
    const i: number = 4;
    const d: number = 4.0;
    const s: string = 'HackerRank ';

    let i2: number = parseInt(readLine());
    let d2: number = parseFloat(readLine());
    let s2: string = readLine();

    console.log(i + i2);
    console.log((d + d2).toFixed(1));
    console.log(s + s2);
}
