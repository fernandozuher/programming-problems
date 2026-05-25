// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

function main() {
  readLine();
  const arr: number[] = readNumbers();
  const ratios: number[] = plusMinus(arr);
  printRatios(ratios);
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
function plusMinus(arr: number[]): number[] {
  let [positive, negative, zero] = [0, 0, 0];

  for (const number of arr)
    if (number > 0) positive++;
    else if (number < 0) negative++;
    else zero++;

  const n: number = arr.length;
  return [positive / n, negative / n, zero / n];
}

function printRatios(ratios: number[]): void {
  for (const ratio of ratios) console.log(ratio.toFixed(6));
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
