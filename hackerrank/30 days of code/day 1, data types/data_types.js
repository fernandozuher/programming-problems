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
    const S = 'HackerRank ';

    let i2 = parseInt(readLine());
    let d2 = parseFloat(readLine());
    let s2 = readLine();

    console.log(I + i2);
    console.log((D + d2).toFixed(1));
    console.log(S + s2);
}
