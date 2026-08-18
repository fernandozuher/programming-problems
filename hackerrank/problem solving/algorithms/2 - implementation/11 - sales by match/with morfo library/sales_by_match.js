// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

import { counter, readLn, skipInputLn, sum } from 'morfo';

skipInputLn();
const socksToCounts = counter(readLn(Number));
console.log(sockMerchant(socksToCounts));

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
function sockMerchant(socksToCounts) {
  return sum(Array.from(socksToCounts.values(), (x) => Math.trunc(x / 2)));
}
