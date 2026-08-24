// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

import { count, countIf, readLn, skipInputLn } from 'morfo';

function main() {
  skipInputLn();
  const arr: number[] = readLn(Number);
  const ratios: number[] = plusMinus(arr);
  printRatios(ratios);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
function plusMinus(arr: number[]): number[] {
  const positive: number = countIf(arr, (number) => number > 0);
  const negative: number = countIf(arr, (number) => number < 0);
  const zero: number = count(arr, 0);

  const n: number = arr.length;
  return [positive / n, negative / n, zero / n];
}

function printRatios(ratios: number[]): void {
  for (const ratio of ratios) console.log(ratio.toFixed(6));
}

main();
