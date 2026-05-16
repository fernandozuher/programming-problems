// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

function main() {
  const initialState = readNumbers();
  console.log(kangaroo(initialState) ? 'YES' : 'NO');
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
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
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
