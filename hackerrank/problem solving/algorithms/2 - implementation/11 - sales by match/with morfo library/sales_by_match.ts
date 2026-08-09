// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

import { counter, readLn, skipInputLn } from 'morfo';

function main() {
  skipInputLn();
  const socksToCounts: Map<number, number> = counter(readLn(Number));
  console.log(sockMerchant(socksToCounts));
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
function sockMerchant(socksToCounts: Map<number, number>): number {
  let pairs = 0;
  for (const x of socksToCounts.values()) pairs += Math.trunc(x / 2);
  return pairs;
}

main();
