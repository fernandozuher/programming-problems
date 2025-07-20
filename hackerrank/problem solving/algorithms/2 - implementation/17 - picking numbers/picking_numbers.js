// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

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
  readLine();
  console.log(pickingNumbers(readNumbers()));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function pickingNumbers(numbers) {
  const counter = new Map();
  for (const num of numbers)
    counter.set(num, (counter.get(num) || 0) + 1);

  let maxLen = 0;
  for (const [num, count] of counter) {
    const current = count + (counter.get(num + 1) || 0);
    maxLen = Math.max(maxLen, current);
  }

  return maxLen;
}
