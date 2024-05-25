// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

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
    let array = readIntArray();
    array.sort((a, b) => a - b);
    miniMaxSum(array);
}

function readIntArray() {
    return readLine().split(' ').map(Number);
}

function miniMaxSum(array) {
    let sum = array.reduce((sum, number) => sum + number, 0);
    let minSum = sum - array[array.length - 1];
    let maxSum = sum - array[0];
    console.log(`${minSum} ${maxSum}`);
}
