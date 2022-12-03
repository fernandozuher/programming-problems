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
 * Complete the 'bitwiseAnd' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER K
 */

function bitwiseAnd(N: number, K: number): number {
    let maximumValueLessThanK: number = 0;
    for (let i: number = 1; i <= N; ++i)
        for (let j: number = i + 1, operation; j <= N; ++j) {
            operation = i & j;
            if (operation < K && operation > maximumValueLessThanK) {
                if (operation == K-1)
                    return operation;
                else
                    maximumValueLessThanK = operation;
            }
        }
    return maximumValueLessThanK;
}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const t: number = parseInt(readLine().trim(), 10);

    for (let tItr: number = 0; tItr < t; tItr++) {
        const firstMultipleInput: string[] = readLine().replace(/\s+$/g, '').split(' ');

        const count: number = parseInt(firstMultipleInput[0], 10);

        const lim: number = parseInt(firstMultipleInput[1], 10);

        const res: number = bitwiseAnd(count, lim);

        ws.write(res + '\n');
    }

    ws.end();
}
