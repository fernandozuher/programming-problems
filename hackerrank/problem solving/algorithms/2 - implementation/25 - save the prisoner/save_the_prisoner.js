// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

function main() {
  const n = +readLine();
  for (let i = 0; i < n; i++) {
    const [prisoners, sweets, startChair] = readNums();
    console.log(saveThePrisoner(prisoners, sweets, startChair));
  }
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// T: O(1)
// S: O(1) extra space
function saveThePrisoner(prisoners, sweets, startChair) {
  return ((startChair - 1 + sweets - 1) % prisoners) + 1;
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
