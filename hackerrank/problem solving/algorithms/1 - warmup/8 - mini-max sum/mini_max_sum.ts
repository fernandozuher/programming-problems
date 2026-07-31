// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

function main() {
  const arr: number[] = readNums();
  const [minSum, maxSum] = calcMinMaxSum(arr);
  console.log(minSum, maxSum);
}

function readNums(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
function calcMinMaxSum(arr: number[]): number[] {
  let total, minValue, maxValue: number;
  total = minValue = maxValue = arr[0];

  for (let i = 1; i < arr.length; i++) {
    total += arr[i];
    minValue = Math.min(minValue, arr[i]);
    maxValue = Math.max(maxValue, arr[i]);
  }

  return [total - maxValue, total - minValue];
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
