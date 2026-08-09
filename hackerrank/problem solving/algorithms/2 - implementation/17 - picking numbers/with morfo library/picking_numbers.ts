// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

import { counter, readLn, skipInputLn } from 'morfo';

function main() {
  skipInputLn();
  const freqMap: Map<number, number> = counter(readLn(Number));
  console.log(pickingNumbers(freqMap));
}

// k: length of freqMap
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
function pickingNumbers(freqMap: Map<number, number>): number {
  let maxLen = 0;
  for (const [num, _] of freqMap) {
    const current: number = freqMap.get(num)! + (freqMap.get(num + 1) || 0);
    maxLen = Math.max(maxLen, current);
  }
  return maxLen;
}

main();
