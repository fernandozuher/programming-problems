// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

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
    const N = 6;
    let matrix = new Array(N).fill([]);
    matrix = matrix.map(_ => readLine().split(' ').map(Number));
    console.log(maxHourglassSum(matrix));
}

    function maxHourglassSum(matrix) {
        let maxSum = -Number.MAX_VALUE;

        for (let i = 1, rowsCols = 4; i <= rowsCols; ++i)
            for (let j = 1; j <= rowsCols; ++j) {
                let currentSum = hourglassSum(matrix, i, j);
                maxSum = Math.max(maxSum, currentSum);
            }

        return maxSum;
    }

        function hourglassSum(matrix, i, j) {
            let subrow1FirstIndex = i - 1;
            let subrow3FirstIndex = i + 1;
            let firstColIndex = j - 1;
            let end = firstColIndex + 3;

            let subrow1Sum = matrix[subrow1FirstIndex].slice(firstColIndex, end).reduce((a, b) => a + b);
            let subrow3Sum = matrix[subrow3FirstIndex].slice(firstColIndex, end).reduce((a, b) => a + b);

            return subrow1Sum + matrix[i][j] + subrow3Sum;
        }
