// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

import { readLn, skipInputLn } from 'morfo';

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
  let [positive, negative, zero] = [0, 0, 0];

  for (const number of arr)
    if (number > 0) positive++;
    else if (number < 0) negative++;
    else zero++;

  const n = arr.length;
  return [positive / n, negative / n, zero / n];
}

function printRatios(ratios) {
  for (const ratio of ratios) console.log(ratio.toFixed(6));
}

main();
