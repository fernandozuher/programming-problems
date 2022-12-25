// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
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

function kangaroo(x1, v1, x2, v2) {
    if (v2 >= v1)
        return "NO";
    for (; x1 < x2; x1 += v1, x2 += v2);
    return x1 === x2 ? "YES" : "NO";
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const numbers = readLine().split(' ').map(Number);
    const x1 = numbers[0];
    const v1 = numbers[1];
    const x2 = numbers[2];
    const v2 = numbers[3];

    const result = kangaroo(x1, v1, x2, v2);
    ws.write(result + '\n');

    ws.end();
}
