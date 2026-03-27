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
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
function minDeletionsToEqualize(arr) {
  let maxCount = 0;
  const freqMap = counter(arr);
  for (const key in freqMap) maxCount = Math.max(maxCount, freqMap[key]);
  return arr.length - maxCount;
}

function counter(arr) {
  let freqMap = {};
  arr.forEach((x) => {
    freqMap[x] = (freqMap[x] ?? 0) + 1;
  });
  return freqMap;
}
