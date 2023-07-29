// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

function main() {
    const I = 4;
    const D = 4.0;
    const S = "HackerRank ";

    const I2 = parseInt(readLine());
    const D2 = parseFloat(readLine());
    const S2 = readLine();

    console.log(I + I2);
    console.log((D + D2).toFixed(1));
    console.log(S + S2);
}
