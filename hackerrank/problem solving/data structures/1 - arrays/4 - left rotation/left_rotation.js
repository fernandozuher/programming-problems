// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

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
    let [n, rotateBy] = readIntArray();
    let array = readIntArray();

    if (rotateBy > n - 1)
        rotateBy %= n;

    array = rotate(array, rotateBy);
    array.forEach(x => process.stdout.write(`${x} `));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function rotate(array, n) {
        return array.concat(array.splice(0, n));
    }
