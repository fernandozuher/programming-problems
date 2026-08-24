// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

import { gcd, lcm, readLn, skipInputLn } from 'morfo';

skipInputLn();
const a = readLn(Number);
const b = readLn(Number);
console.log(betweenTwoSets(a, b));

// n1, n2: length of a, b
// k: number of multiples tested = gcdOfB / lcmOfA
// T: O(n1 + n2 + k)
// S: O(1) extra space
function betweenTwoSets(a, b) {
  const lcmOfA = lcm(a);
  const gcdOfB = gcd(b);

  let count = 0;
  for (let i = lcmOfA; i <= gcdOfB; i += lcmOfA) {
    if (gcdOfB % i === 0) count++;
  }
  return count;
}
