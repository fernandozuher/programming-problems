// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

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
    let [n, rotateBy]: number[] = readIntArray();
    let array: number[] = readIntArray();

    if (rotateBy > n - 1)
        rotateBy %= n;

    array = rotate(array, rotateBy);
    array.forEach(x => process.stdout.write(`${x} `));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function rotate(array: number[], n: number): number[] {
        return array.concat(array.splice(0, n));
    }
