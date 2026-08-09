// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

import { println, readLn, skipInputLn } from 'morfo';

function main() {
  skipInputLn();
  const arr: number[] = readLn(Number);
  arr.sort((a, b) => a - b);
  println(cutTheSticks(arr));
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

main();
