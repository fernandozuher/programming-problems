// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

function main() {
  const [_, t] = readNumbers();
  const widths = readNumbers();
  for (let i = 0; i < t; i++)
    console.log(minWidthInSegment(widths, readNumbers()));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
function minWidthInSegment(widths, segment) {
  const [start, finish] = segment;
  let minEl = widths[start];
  for (let i = start; i <= finish; ++i) minEl = Math.min(minEl, widths[i]);
  return minEl;
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
