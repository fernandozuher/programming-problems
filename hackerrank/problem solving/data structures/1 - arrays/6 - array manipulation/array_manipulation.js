// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

function main() {
  const [n, nQueries] = readNums();
  console.log(arrayManipulation(n, nQueries));
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// T: O(n + nQueries)
// S: O(n) extra space
function arrayManipulation(n, nQueries) {
  const arr = populateArr(n, nQueries);
  return maxSequentialSum(arr);
}

function populateArr(n, nQueries) {
  // +2 = 1-indexed array + range-end
  const arr = new Array(n + 2).fill(0);

  for (let i = 0; i < nQueries; i++) {
    const [b, e, summand] = readNums();
    arr[b] += summand;
    arr[e + 1] -= summand;
  }

  return arr;
}

function maxSequentialSum(arr) {
  let sum = 0;
  let max = 0;

  for (const x of arr) {
    sum += x;
    max = Math.max(max, sum);
  }

  return max;
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
