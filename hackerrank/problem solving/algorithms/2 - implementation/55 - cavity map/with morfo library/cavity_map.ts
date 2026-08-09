// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

import { read, println } from 'morfo';

const n: number = read(Number);
const matrix: string[][] = readMatrix(n);
changeMatrixToCavityMap(matrix);
println(matrix.map((x) => x.join('')));

function readMatrix(n: number): string[][] {
  return Array(n)
    .fill('0')
    .map((_) => read(String).split(''));
}

// n: length of matrix' rows
// T: O(n^2)
// S: O(1) extra space
function changeMatrixToCavityMap(matrix: string[][]) {
  for (let i = 1, n = matrix.length - 1; i < n; i++)
    for (let j = 1; j < n; j++)
      if (isCellCavity(matrix, i, j)) matrix[i][j] = 'X';
}

function isCellCavity(matrix: string[][], i: number, j: number): boolean {
  const c: string = matrix[i][j];
  return (
    matrix[i - 1][j] < c &&
    matrix[i][j - 1] < c &&
    matrix[i + 1][j] < c &&
    matrix[i][j + 1] < c
  );
}
