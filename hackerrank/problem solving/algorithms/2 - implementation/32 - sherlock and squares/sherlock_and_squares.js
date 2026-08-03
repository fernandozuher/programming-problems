// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

function main() {
  const n = +readLine();
  for (let i = 0; i < n; i++) {
    const [a, b] = readNums();
    console.log(squares(a, b));
  }
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// T: O(1)
// S: O(1) extra space
function squares(startNum, endNum) {
  const minSquare = Math.ceil(Math.sqrt(startNum));
  const maxSquare = Math.floor(Math.sqrt(endNum));
  return maxSquare - minSquare + 1;
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
