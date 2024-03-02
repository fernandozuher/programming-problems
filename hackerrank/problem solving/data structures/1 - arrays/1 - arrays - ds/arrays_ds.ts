// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

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
    let n: number = +readLine();
    let array: number[] = readLine().split(' ').map(Number);
    array = reverseArray(array);
    array.forEach(x => process.stdout.write(x + ' '));
}

    function reverseArray(array: number[]): number[] {
        return array.reverse();
    }
