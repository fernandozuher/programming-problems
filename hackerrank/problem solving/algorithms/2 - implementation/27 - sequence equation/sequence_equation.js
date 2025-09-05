// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

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
  const arr = readNumbers();
  sequenceEquation(arr).forEach((val) => console.log(val));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function sequenceEquation(arr) {
  const valuesToIndex = Array(arr.length).fill(0);
  let i = 0;
  for (const val of arr) valuesToIndex[val - 1] = i++;

  const res = Array(arr.length).fill(0);
  i = 0;
  for (const val of valuesToIndex) {
    res[i++] = valuesToIndex[val] + 1;
  }

  return res;
}
