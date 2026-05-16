// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

function main() {
  const n = +readLine();
  const page = +readLine();
  console.log(pageCount(n, page));
}

// T: O(1)
// S: O(1) extra space
function pageCount(n, page) {
  const fromFront = Math.trunc(page / 2);
  const fromBack = Math.trunc(n / 2) - fromFront;
  return Math.min(fromFront, fromBack);
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
