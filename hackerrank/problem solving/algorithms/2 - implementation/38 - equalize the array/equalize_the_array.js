// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

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
  readLine();
  console.log(equalizeArray(readNumbers()));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function equalizeArray(arr) {
  const maxCount = Math.max(...Object.values(counter(arr)));
  return arr.length - maxCount;
}

function counter(arr) {
  let counter = {};
  arr.forEach((x) => {
    counter[x] = (counter[x] ?? 0) + 1;
  });
  return counter;
}
