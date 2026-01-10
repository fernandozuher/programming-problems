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

function readLine() {
  return inputLines[currentLine++];
}

////////////////////////////////////////////////

function main() {
  readLine();
  console.log(pickingNumbers(counter()));
}

function counter() {
  const arr = readLine().split(' ').map(Number);
  const frequency = new Map();
  for (const num of arr) {
    frequency.set(num, (frequency.get(num) || 0) + 1);
  }
  return frequency;
}

// n: length of initial input array of numbers
// k: length of map frequency
// T:
//   Without constraining the input values:
//       In the worst case, length of map equals length of initial input array when there is no repeated element: k = n
//       O(n)
//   With input values limited to 1 through 99, as stated in the problem:
//       Max of 99 keys/values at map: O(99) = O(1)
// S: O(1) extra space
function pickingNumbers(frequency) {
  let maxLen = 0;
  for (const [num, _] of frequency) {
    const current = frequency.get(num) + (frequency.get(num + 1) || 0);
    maxLen = Math.max(maxLen, current);
  }
  return maxLen;
}
