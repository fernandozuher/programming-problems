// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

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
  const [_, nRotation, nQueries] = readNumbers();
  const arr = readNumbers();
  printQueries(arr, nRotation, nQueries);
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function printQueries(arr, nRotation, nQueries) {
  const n = arr.length;
  const r = nRotation % n;
  for (let i = 0; i < nQueries; i++) {
    const query = +readLine();
    const idx = (query + n - r) % n;
    console.log(arr[idx]);
  }
}
