// Source: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    const N_ROWS_COLUMNS = +readLine();
    const MATRIX = Array(N_ROWS_COLUMNS).fill('0').map(_ => readLine().split(''));
    changeMatrixToCavityMap(MATRIX);
    MATRIX.forEach(element => console.log(element.join('')));
}

    function changeMatrixToCavityMap(matrix) {
        const CAVITY = 'X';
        for (let i = 1, newSize = matrix.length - 1; i < newSize; i++)
            for (let j = 1; j < newSize; j++)
                if (isCellCavity(matrix, i, j))
                    matrix[i][j] = CAVITY;
    }

        function isCellCavity(matrix, i, j) {
            return matrix[i - 1][j] < matrix[i][j]
                && matrix[i][j - 1] < matrix[i][j]
                && matrix[i + 1][j] < matrix[i][j]
                && matrix[i][j + 1] < matrix[i][j];
        }
