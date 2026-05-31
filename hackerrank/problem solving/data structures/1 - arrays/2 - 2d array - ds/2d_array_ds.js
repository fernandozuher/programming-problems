// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

function main() {
  const matrix = readMatrix();
  console.log(maxHourglassSum(matrix));
}

function readMatrix() {
  const N = 6;
  return new Array(N).fill([]).map(readNumbers);
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(1)
// S: O(1) extra space
function maxHourglassSum(matrix) {
  let maxSum = -Number.MAX_VALUE;

  for (let i = 1, rowsCols = 4; i <= rowsCols; i++)
    for (let j = 1; j <= rowsCols; j++) {
      const currentSum = hourglassSum(matrix, i, j);
      maxSum = Math.max(maxSum, currentSum);
    }

  return maxSum;
}

function hourglassSum(matrix, i, j) {
  const subrow1FirstIndex = i - 1;
  const subrow3FirstIndex = i + 1;
  const firstColIndex = j - 1;
  const end = firstColIndex + 3;

  const subrow1Sum = matrix[subrow1FirstIndex]
    .slice(firstColIndex, end)
    .reduce((a, b) => a + b);
  const subrow3Sum = matrix[subrow3FirstIndex]
    .slice(firstColIndex, end)
    .reduce((a, b) => a + b);

  return subrow1Sum + matrix[i][j] + subrow3Sum;
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
