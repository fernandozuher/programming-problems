// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

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
    let n = +readLine();
    let array = readLine().split(' ').map(Number);
    array = reverseArray(array);
    array.forEach(x => process.stdout.write(x + ' '));
}

    function reverseArray(array) {
        return array.reverse();
    }
