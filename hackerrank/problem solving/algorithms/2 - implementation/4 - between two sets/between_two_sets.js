// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

function main() {
  readLine();
  const a = readNumbers();
  const b = readNumbers();
  console.log(betweenTwoSets(a, b));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n1, n2: length of a, b
// k: number of multiples tested = gcdOfB / lcmOfA
// T: O(n1 + n2 + k)
// S: O(1) extra space
function betweenTwoSets(a, b) {
  const lcmOfA = a.reduce(lcm);
  const gcdOfB = b.reduce(gcd);

  let count = 0;
  for (let i = lcmOfA; i <= gcdOfB; i += lcmOfA) {
    if (gcdOfB % i === 0) count++;
  }
  return count;
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}

function gcd(a, b) {
  while (b !== 0) {
    const t = b;
    b = a % b;
    a = t;
  }
  return a;
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
