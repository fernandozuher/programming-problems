// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const initialState = readNumbers();
  console.log(kangaroo(initialState) ? 'YES' : 'NO');
}

function readNumbers() {
  return readLine().split(' ').map(Number);
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
