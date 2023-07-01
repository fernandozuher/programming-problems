// Source: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

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
    const N_ROWS_COLUMNS: number = +readLine();
    const MATRIX: Array<Array<string>> = Array(N_ROWS_COLUMNS).fill('0').map(_ => readLine().split(''));
    changeMatrixToCavityMap(MATRIX);
    MATRIX.forEach(element => console.log(element.join('')));
}

    function changeMatrixToCavityMap(matrix: Array<Array<string>>) {
        const CAVITY: string = 'X';
        for (let i = 1, newSize = matrix.length - 1; i < newSize; i++)
            for (let j = 1; j < newSize; j++)
                if (isCellCavity(matrix, i, j))
                    matrix[i][j] = CAVITY;
    }

        function isCellCavity(matrix: Array<Array<string>>, i: number, j: number): boolean {
            return matrix[i - 1][j] < matrix[i][j]
                && matrix[i][j - 1] < matrix[i][j]
                && matrix[i + 1][j] < matrix[i][j]
                && matrix[i][j + 1] < matrix[i][j];
        }
