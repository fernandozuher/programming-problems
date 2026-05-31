// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

function main() {
  const matrix: number[][] = readMatrix();
  console.log(maxHourglassSum(matrix));
}

function readMatrix(): number[][] {
  const N: number = 6;
  return new Array(N).fill([]).map(readNumbers);
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(1)
// S: O(1) extra space
function maxHourglassSum(matrix: number[][]): number {
  let maxSum: number = -Number.MAX_VALUE;

  for (let i = 1, rowsCols = 4; i <= rowsCols; i++)
    for (let j = 1; j <= rowsCols; j++) {
      const currentSum: number = hourglassSum(matrix, i, j);
      maxSum = Math.max(maxSum, currentSum);
    }

  return maxSum;
}

function hourglassSum(matrix: number[][], i: number, j: number): number {
  const subrow1FirstIndex: number = i - 1;
  const subrow3FirstIndex: number = i + 1;
  const firstColIndex: number = j - 1;
  const end: number = firstColIndex + 3;

  const subrow1Sum: number = matrix[subrow1FirstIndex]
    .slice(firstColIndex, end)
    .reduce((a, b) => a + b);
  const subrow3Sum: number = matrix[subrow3FirstIndex]
    .slice(firstColIndex, end)
    .reduce((a, b) => a + b);

  return subrow1Sum + matrix[i][j] + subrow3Sum;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
