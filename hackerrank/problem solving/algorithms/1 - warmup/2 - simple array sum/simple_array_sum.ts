// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

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
    let n: number = +readLine();
    let array: number[] = readLine().split(' ').map(Number);
    console.log(simpleArraySum(array));
}

    function simpleArraySum(array: number[]): number {
        return array.reduce((sum, num) => sum + num, 0);
    }
