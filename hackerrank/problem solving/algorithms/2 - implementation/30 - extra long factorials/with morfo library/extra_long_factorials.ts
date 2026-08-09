// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

import { read } from 'morfo';

const n: number = read(Number);
console.log(factorial(n).toString());

// T: O(n)
// S: O(1) extra space (excluding the size of the resulting integer)
function factorial(n: number): BigInt {
  let res = BigInt(1);
  for (let i = BigInt(1); i <= n; i++) res *= i;
  return res;
}
