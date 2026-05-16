// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

function main() {
  readLine();
  const a: number[] = readNumbers();
  const b: number[] = readNumbers();
  console.log(betweenTwoSets(a, b));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
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

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
