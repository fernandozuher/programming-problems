// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
  let numbers = readInput();
  let nSwaps = bubbleSort(numbers);
  console.log(`Array is sorted in ${nSwaps} swaps.`);
  console.log(`First Element: ${numbers[0]}`);
  console.log(`Last Element: ${numbers.at(-1)}`);
}

function readInput() {
  readLine(); // Skip size of elements
  return readLine().split(' ').map(Number);
}

function bubbleSort(a) {
  let totalSwaps = 0;
  for (let end = a.length; end > 0; ) {
    let [nSwaps, newEnd] = sortSlice(a, end);
    totalSwaps += nSwaps;
    end = newEnd;
  }
  return totalSwaps;
}

function sortSlice(a, end) {
  let nSwaps = 0;
  let newEnd = 0;
  --end; // Decrease end to avoid out of range error
  for (let i = 0; i < end; i++) {
    if (a[i] > a[i + 1]) {
      [a[i], a[i + 1]] = [a[i + 1], a[i]];
      ++nSwaps;
      newEnd = i + 1;
    }
  }
  return [nSwaps, newEnd];
}
