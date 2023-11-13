// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

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
    let n: number = +readLine();
    let matrix: number[][] = readMatrix(n);
    console.log(diagonalDifference(matrix));
}

    function readMatrix(n: number): number[][] {
        let matrix: number[][] = [];
        for (let i = 0; i < n; ++i)
            matrix.push(readLine().split(' ').map(Number));
        return matrix;
    }

    function diagonalDifference(matrix: number[][]): number {
        let [primaryDiagonal, secondaryDiagonal]: number[] = [0, 0];

        for (let i = 0, j = matrix.length - 1, n = matrix.length; i < n; ++i, --j) {
            primaryDiagonal += matrix[j][j];
            secondaryDiagonal += matrix[j][i];
        }

        return Math.abs(primaryDiagonal - secondaryDiagonal);
    }
