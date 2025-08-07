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

//////////////////////////////////////////////////

function main() {
  const n = +readLine();
  Array.from({ length: n })
    .map((_) => {
      const [prisoners, sweets, startChair] = readNumbers();
      return saveThePrisoner(prisoners, sweets, startChair);
    })
    .forEach((x) => console.log(x));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function saveThePrisoner(prisoners, sweets, startChair) {
  return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
