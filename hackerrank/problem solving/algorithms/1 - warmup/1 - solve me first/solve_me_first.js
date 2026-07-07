// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

function main() {
  const n1 = +readLine();
  const n2 = +readLine();
  console.log(solveMeFirst(n1, n2));
}

// T: O(1)
// S: O(1) extra space
function solveMeFirst(n1, n2) {
  return n1 + n2;
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
