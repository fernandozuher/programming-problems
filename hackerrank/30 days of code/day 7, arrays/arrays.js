// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

'use strict';

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

function main() {
  readLine(); // Ignore not used n
  let array = readLine().split(' ').map(Number);
  array.findLast(x => {
    process.stdout.write(`${x} `);
  });
}
