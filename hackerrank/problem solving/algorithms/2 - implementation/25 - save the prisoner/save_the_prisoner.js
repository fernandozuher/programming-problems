// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

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
  const n = +readLine();
  for (let i = 0; i < n; i++) {
    const [prisoners, sweets, startChair] = readNumbers();
    console.log(saveThePrisoner(prisoners, sweets, startChair));
  }
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

// T: O(1)
// S: O(1) extra space
function saveThePrisoner(prisoners, sweets, startChair) {
  return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
