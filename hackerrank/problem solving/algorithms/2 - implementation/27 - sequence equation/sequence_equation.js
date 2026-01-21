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
  for (const x of sequenceEquation(arr)) console.log(x);
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

// n: length of array arr/output
// T: O(n)
// S: O(n) extra space
function sequenceEquation(arr) {
  const valuesToIndex = Array(arr.length).fill(0);
  let i = 0;
  for (const val of arr) valuesToIndex[val - 1] = i++;
  return valuesToIndex.map(val => valuesToIndex[val] + 1);
}
