// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

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
    console.log(findDigits(+readLine()));
  }
}

function findDigits(n) {
  return n
    .toString()
    .split('')
    .map(Number)
    .filter((d) => d !== 0 && n % d === 0).length;
}
