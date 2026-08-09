// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

import { skipInput, read, readLn } from 'morfo';

skipInput();
const jumpLength = read(Number);
const arr = readLn(Number);
console.log(jumpingOnTheClouds(arr, jumpLength));

// n: length of clouds; 2 to 25
// k (jumpLength): 1 <= k <= n
// n % k = 0
// c[i] = 0 or 1
// T: O(n) = O(25) = O(1)
// S: O(1) extra space
function jumpingOnTheClouds(clouds, jumpLength) {
  let energy = 100;

  for (let cloudIndex = 0; ; ) {
    energy -= clouds[cloudIndex] === 0 ? 1 : 3;
    cloudIndex = (cloudIndex + jumpLength) % clouds.length;
    if (!cloudIndex) break;
  }

  return energy;
}
