// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

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
    let array = readLine().split(' ').map(Number);
    console.log(simpleArraySum(array));
}

    function simpleArraySum(array) {
        return array.reduce((sum, num) => sum + num, 0);
    }
