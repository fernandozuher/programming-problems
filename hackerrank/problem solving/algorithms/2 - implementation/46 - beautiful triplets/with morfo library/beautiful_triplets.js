// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

import { skipInput, read, readLn } from 'morfo';

function main() {
  skipInput();
  const beautifulDifference = read(Number);
  const arr = readLn(Number);
  console.log(findBeautifulTriplets(arr, beautifulDifference));
}

// n: length of arr
// k: distinct numbers of arr
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
function findBeautifulTriplets(arr, beautifulDifference) {
  const values = new Set(arr);
  const doubleBD = 2 * beautifulDifference;
  let count = 0;

  for (const x of arr) {
    if (values.has(x + beautifulDifference) && values.has(x + doubleBD))
      count++;
  }

  return count;
}

main();
