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
  for (const q of queries(arr, nRotation, nQueries)) console.log(q);
}

function readNumbers() {
  return readLine().split(' ').map(Number);
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
