// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    +readLine();
    let array: number[] = readIntArray();
    console.log(aVeryBigSum(array));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function aVeryBigSum(array: number[]): number {
        return array.reduce((a, b) => a + b);
    }
