// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

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
    let num1 = +readLine();
    let num2 = +readLine();
    console.log(solveMeFirst(num1, num2));
}

    function solveMeFirst(a, b) {
        return a + b;
    }
