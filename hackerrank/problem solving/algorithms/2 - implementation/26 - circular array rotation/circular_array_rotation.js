// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

function main() {
  const [_, nRotation, nQueries] = readNumbers();
  const arr = readNumbers();
  for (const q of queries(arr, nRotation, nQueries)) console.log(q);
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(nQueries)
// S: O(1) extra space
function* queries(arr, nRotation, nQueries) {
  const offset = nRotation % arr.length;
  for (let i = 0; i < nQueries; i++) {
    const query = +readLine();
    yield arr.at(query - offset);
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
