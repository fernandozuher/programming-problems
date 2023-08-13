// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

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
    const MATRIX = readMatrix();
    const MAX_SUM = calculateMaxSum(MATRIX);
    console.log(MAX_SUM);
}

    function readMatrix() {
        const N_ROWS_COLUMNS = 6;
        const MATRIX = Array(N_ROWS_COLUMNS).fill(0)
                                            .map(_ => readLine().split(' ')
                                                                .map(Number));
        return MATRIX;
    }

    function calculateMaxSum(matrix) {
        let maxSum = Number.MIN_SAFE_INTEGER;

        for (let i = 1, beforeRowsColumnsLimit = 5; i < beforeRowsColumnsLimit; i++)
            for (let j = 1; j < beforeRowsColumnsLimit; j++)
                maxSum = Math.max(maxSum, sumAround(matrix, i, j));

        return maxSum;
    }

        function sumAround(matrix, i, j) {
            return matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] +
                   matrix[i][j] +
                   matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
        }
