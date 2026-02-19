// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const n = +readLine();
  const matrix = readMatrix(n);
  changeMatrixToCavityMap(matrix);
  for (const x of matrix) console.log(x.join(''));
}

function readMatrix(n) {
  return Array(n)
    .fill('0')
    .map((_) => readLine().split(''));
}

// n: length of rows/cols of matrix
// T: O(n^2)
// S: O(1) extra space
function changeMatrixToCavityMap(matrix) {
  for (let i = 1, n = matrix.length - 1; i < n; i++)
    for (let j = 1; j < n; j++)
      if (isCellCavity(matrix, i, j)) matrix[i][j] = 'X';
}

function isCellCavity(matrix, i, j) {
  const c = matrix[i][j];
  return (
    matrix[i - 1][j] < c &&
    matrix[i][j - 1] < c &&
    matrix[i + 1][j] < c &&
    matrix[i][j + 1] < c
  );
}
