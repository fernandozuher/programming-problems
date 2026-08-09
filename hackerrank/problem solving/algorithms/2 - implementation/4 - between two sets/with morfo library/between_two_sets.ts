// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

import { skipInputLn, readLn } from 'morfo';

function main() {
  skipInputLn();
  const a: number[] = readLn(Number);
  const b: number[] = readLn(Number);
  console.log(betweenTwoSets(a, b));
}

// n1, n2: length of a, b
// k: number of multiples tested = gcdOfB / lcmOfA
// T: O(n1 + n2 + k)
// S: O(1) extra space
function betweenTwoSets(a: number[], b: number[]): number {
  const lcmOfA: number = a.reduce(lcm);
  const gcdOfB: number = b.reduce(gcd);

  let count = 0;
  for (let i = lcmOfA; i <= gcdOfB; i += lcmOfA) {
    if (gcdOfB % i === 0) count++;
  }
  return count;
}

function lcm(a: number, b: number): number {
  return (a * b) / gcd(a, b);
}

function gcd(a: number, b: number): number {
  while (b !== 0) {
    const t = b;
    b = a % b;
    a = t;
  }
  return a;
}

main();
