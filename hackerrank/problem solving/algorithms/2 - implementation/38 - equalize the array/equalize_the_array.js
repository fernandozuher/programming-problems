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
  console.log(minDeletionsToEqualize(readNumbers()));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

// n: length of arr, 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(n) = O(100) = O(1) extra space
function minDeletionsToEqualize(arr) {
  return arr.length - Math.max(...Object.values(counter(arr)));
}

function counter(arr) {
  let counter = {};
  arr.forEach((x) => {
    counter[x] = (counter[x] ?? 0) + 1;
  });
  return counter;
}
