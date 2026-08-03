// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

function main() {
  const maxJump = readNums()[1];
  const hurdles = readNums();
  console.log(hurdleRace(hurdles, maxJump));
}

function readNums() {
  return readLine().split(' ').map(Number);
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
const inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
