// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

function main() {
    let matrix: number[][] = readMatrix();
    let max_sum: number = calculateMaxSum(matrix);
    console.log(max_sum);
}

    function readMatrix(): number[][] {
        const N_ROWS_COLUMNS: number = 6;
        let matrix: number[][] = Array(N_ROWS_COLUMNS).fill(0).map(_ => readLine().split(' ').map(Number));
        return matrix;
    }

    function calculateMaxSum(matrix: number[][]): number {
        let maxSum: number = Number.MIN_SAFE_INTEGER;

        for (let i = 1, beforeRowsColumnsLimit = 5; i < beforeRowsColumnsLimit; i++)
            for (let j = 1; j < beforeRowsColumnsLimit; j++)
                maxSum = Math.max(maxSum, sumAround(matrix, i, j));

        return maxSum;
    }

        function sumAround(matrix: number[][], i: number, j: number): number {
            return matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] +
                   matrix[i][j] +
                   matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
        }
