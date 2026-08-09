// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

import { skipInputLn, readLn } from 'morfo';

skipInputLn();
const arr = readLn(Number);
console.log(minDistance(arr));

// n: length of arr
// T: O(n)
// S: O(n) extra space
function minDistance(arr) {
  const lastSeen = {};
  let minDist = -1;

  for (let i = 0; i < arr.length; i++) {
    const x = arr[i];

    if (lastSeen.hasOwnProperty(x)) {
      const dist = i - lastSeen[x];

      if (minDist === -1 || dist < minDist) {
        minDist = dist;
        if (minDist === 1) return 1;
      }
    }

    lastSeen[x] = i;
  }

  return minDist;
}
