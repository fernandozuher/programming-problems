// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

function main() {
  const initialState = readNums();
  console.log(kangaroo(initialState) ? 'YES' : 'NO');
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// T: O(1)
// S: O(1) extra space
function kangaroo(initialState) {
  const [x1, v1, x2, v2] = initialState;

  if (v1 === v2) return x1 === x2;

  const distanceDiff = x2 - x1;
  const velocityDiff = v1 - v2;
  return distanceDiff * velocityDiff >= 0 && distanceDiff % velocityDiff === 0;
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
