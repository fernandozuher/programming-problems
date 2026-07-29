// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

import { skipInputLn, readLn } from 'morfo';

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

main();
