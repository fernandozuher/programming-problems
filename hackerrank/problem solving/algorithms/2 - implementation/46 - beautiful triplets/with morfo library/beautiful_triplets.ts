// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

import { skipInput, read, readLn } from 'morfo';

function main() {
  skipInput();
  const beautifulDifference: number = read(Number);
  const arr: number[] = readLn(Number);
  console.log(findBeautifulTriplets(arr, beautifulDifference));
}

// n: length of arr
// k: distinct numbers of arr
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
function findBeautifulTriplets(
  arr: number[],
  beautifulDifference: number,
): number {
  const values: Set<number> = new Set(arr);
  const doubleBD: number = 2 * beautifulDifference;
  let count: number = 0;

  for (const x of arr) {
    if (values.has(x + beautifulDifference) && values.has(x + doubleBD))
      count++;
  }

  return count;
}

main();
