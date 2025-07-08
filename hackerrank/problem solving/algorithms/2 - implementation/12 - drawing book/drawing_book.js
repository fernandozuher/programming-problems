// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
  const n = +readLine();
  const page = +readLine();
  console.log(pageCount(n, page));
}

function readLine() {
  return inputLines[currentLine++];
}

function pageCount(n, page) {
  const fromFront = Math.trunc(page / 2);
  const fromBack = Math.trunc(n / 2) - fromFront;
  return Math.min(fromFront, fromBack);
}
