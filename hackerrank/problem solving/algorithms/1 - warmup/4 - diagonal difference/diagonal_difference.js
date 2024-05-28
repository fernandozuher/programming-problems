// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

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
    console.log(diagonalDifference(n));
}

    function diagonalDifference(n) {
        let [primaryDiagonal, secondaryDiagonal] = [0, 0];
        for (let i = 0; i < n; ++i) {
            let line = readIntArray();
            primaryDiagonal += line[i];
            secondaryDiagonal += line[n - i - 1];
        }
        return Math.abs(primaryDiagonal - secondaryDiagonal);
    }

        function readIntArray() {
            return readLine().split(' ').map(Number);
        }
