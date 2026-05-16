// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

function main() {
  readLine();
  const arr: number[] = readNumbers();
  arr.sort((a, b) => a - b);
  for (const x of cutTheSticks(arr)) console.log(x);
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// k: number of distinct values in arr
// k <= n
// T: O(n)
//    Sorting arr beforehand is O(n log n)
// S: O(k) = O(n) extra space
//    Sorting arr beforehand is O(n) extra space
function cutTheSticks(arr: number[]): number[] {
  const res: number[] = [];
  let slow = 0;
  const n: number = arr.length;

  for (let fast = 0; fast < n; fast++) {
    if (arr[slow] === arr[fast]) continue;
    res.push(n - slow);
    slow = fast;
  }

  res.push(n - slow);
  return res;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
