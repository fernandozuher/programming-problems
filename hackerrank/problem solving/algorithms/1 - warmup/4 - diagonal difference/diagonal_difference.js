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

function main() {
    let n = +readLine();
    let matrix = readMatrix(n);
    console.log(diagonalDifference(matrix));
}

    function readMatrix(n) {
        let matrix = [];
        for (let i = 0; i < n; ++i)
            matrix.push(readLine().split(' ').map(Number));
        return matrix;
    }

    function diagonalDifference(matrix) {
        let [primaryDiagonal, secondaryDiagonal] = [0, 0];
        for (let i = 0, j = matrix.length - 1, n = matrix.length; i < n; ++i, --j) {
            primaryDiagonal += matrix[j][j];
            secondaryDiagonal += matrix[j][i];
        }
        return Math.abs(primaryDiagonal - secondaryDiagonal);
    }
