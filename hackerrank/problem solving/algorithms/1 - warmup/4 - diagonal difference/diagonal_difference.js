// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

function main() {
  const n = +readLine();
  console.log(diagonalDifference(n));
}

// T: O(n^2)
// S: O(n) extra space
function diagonalDifference(n) {
  let [primarySum, secondarySum] = [0, 0];

  for (let i = 0; i < n; i++) {
    const arr = readNums();
    primarySum += arr[i];
    secondarySum += arr.at(-i - 1);
  }

  return Math.abs(primarySum - secondarySum);
}

function readNums() {
  return readLine().split(' ').map(Number);
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
