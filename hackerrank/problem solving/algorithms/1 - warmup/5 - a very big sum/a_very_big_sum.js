// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

function main() {
  readLine();
  const arr = readNumbers();
  console.log(aVeryBigSum(arr));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
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
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
