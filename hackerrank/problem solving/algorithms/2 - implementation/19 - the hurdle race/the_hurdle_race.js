// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

function main() {
  const maxJump = readNumbers()[1];
  const hurdles = readNumbers();
  console.log(hurdleRace(hurdles, maxJump));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
function hurdleRace(hurdles, maxJump) {
  return Math.max(0, Math.max(...hurdles) - maxJump);
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
