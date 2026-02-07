// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

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
  const [, beautifulDifference] = readNumbers();
  const arr = readNumbers();
  console.log(findBeautifulTriplets(arr, beautifulDifference));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

// n: length of array arr
// T: O(n)
// S: O(n) extra space
function findBeautifulTriplets(arr, beautifulDifference) {
  const values = new Set(arr);
  const doubleBD = 2 * beautifulDifference;
  let count = 0;

  for (const x of arr) {
    if (values.has(x + beautifulDifference) && values.has(x + doubleBD))
      count++;
  }

  return count;
}
