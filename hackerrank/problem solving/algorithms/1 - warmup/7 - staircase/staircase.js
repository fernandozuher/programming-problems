// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

function main() {
  const n = +readLine();
  staircase(n);
}

// T: O(n^2)
// S: O(n) extra space
function staircase(n) {
  for (let i = 1; i <= n; i++) {
    const spaces = ' '.repeat(n - i);
    const hashes = '#'.repeat(i);
    console.log(spaces + hashes);
  }
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
