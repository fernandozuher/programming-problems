// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

function main() {
  const arr: number[] = readNumbers();
  const [minSum, maxSum] = calcMinMaxSum(arr);
  console.log(minSum, maxSum);
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
function calcMinMaxSum(arr: number[]): number[] {
  let sum, min, max: number;
  sum = min = max = arr[0];

  for (let i = 1; i < arr.length; i++) {
    sum += arr[i];
    min = Math.min(min, arr[i]);
    max = Math.max(max, arr[i]);
  }

  return [sum - max, sum - min];
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
