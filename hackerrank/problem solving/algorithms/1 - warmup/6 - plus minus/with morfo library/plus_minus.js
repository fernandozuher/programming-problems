// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

import { count, countIf, readLn, skipInputLn } from 'morfo';

function main() {
  skipInputLn();
  const arr = readLn(Number);
  const ratios = plusMinus(arr);
  printRatios(ratios);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
function plusMinus(arr) {
  const positive = countIf(arr, (number) => number > 0);
  const negative = countIf(arr, (number) => number < 0);
  const zero = count(arr, 0);

  const n = arr.length;
  return [positive / n, negative / n, zero / n];
}

function printRatios(ratios) {
  for (const ratio of ratios) console.log(ratio.toFixed(6));
}

main();
