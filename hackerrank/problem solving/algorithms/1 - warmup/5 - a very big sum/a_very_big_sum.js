// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

function main() {
  readLine();
  const arr = readNums();
  console.log(aVeryBigSum(arr));
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
function aVeryBigSum(arr) {
  return arr.reduce((a, b) => a + b);
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
