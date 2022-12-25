// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

'use strict';

import { WriteStream, createWriteStream } from "fs";
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

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

function kangaroo(x1: number, v1: number, x2: number, v2: number): string {
    if (v2 >= v1)
        return "NO";
    for (; x1 < x2; x1 += v1, x2 += v2);
    return x1 === x2 ? "YES" : "NO";
}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const numbers = readLine().split(' ').map(Number);
    const x1 = numbers[0];
    const v1 = numbers[1];
    const x2 = numbers[2];
    const v2 = numbers[3];

    const result: string = kangaroo(x1, v1, x2, v2);
    ws.write(result + '\n');

    ws.end();
}
