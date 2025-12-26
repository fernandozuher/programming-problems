// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

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
  const [_, t] = readNumbers();
  const widths = readNumbers();
  for (let i = 0; i < t; i++)
    console.log(minWidthInSegment(widths, readNumbers()));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function minWidthInSegment(widths, segment) {
  return Math.min(...widths.slice(segment[0], segment[1] + 1));
}
