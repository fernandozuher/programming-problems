// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    +readLine();
    let array = readIntArray();
    console.log(aVeryBigSum(array));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function aVeryBigSum(array) {
        return array.reduce((a, b) => a + b);
    }
