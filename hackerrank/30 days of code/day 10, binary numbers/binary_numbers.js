// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

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
    let n = +readLine();
    let maxOnes = 0, ones = 0;

    for (; n > 0; n = Math.trunc(n / 2)) {
        if (n % 2 == 1)
            ++ones;
        else {
            maxOnes = Math.max(maxOnes, ones);
            ones = 0;
        }
    }

    maxOnes = Math.max(maxOnes, ones);
    console.log(maxOnes);
}
