// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    const N: number = 6;
    let matrix: number[][] = new Array(N).fill([]);
    matrix = matrix.map(_ => readLine().split(' ').map(Number));
    console.log(maxHourglassSum(matrix));
}

    function maxHourglassSum(matrix: number[][]): number {
        let maxSum: number = -Number.MAX_VALUE;

        for (let i = 1, rowsCols = 4; i <= rowsCols; ++i)
            for (let j = 1; j <= rowsCols; ++j) {
                let currentSum: number = hourglassSum(matrix, i, j);
                maxSum = currentSum > maxSum ? currentSum : maxSum;
            }

        return maxSum;
    }

        function hourglassSum(matrix: number[][], i: number, j: number): number {
            return matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1]
                   + matrix[i][j] +
                   matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
        }
