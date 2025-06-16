// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
  inputString += inputStdin;
});

process.stdin.on('end', function (): void {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

//////////////////////////////////////////////////

function main() {
  readLine();
  const numbersA: number[] = readNumbers();
  const numbersB: number[] = readNumbers();
  console.log(betweenTwoSets(numbersA, numbersB));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function betweenTwoSets(a: number[], b: number[]): number {
  const lcmOfA: number = lcmArray(a);
  const gcdOfB: number = gcdArray(b);

  let count = 0;
  for (let i = lcmOfA; i <= gcdOfB; i += lcmOfA) {
    if (gcdOfB % i === 0) count++;
  }
  return count;
}

function lcmArray(numbers: number[]): number {
  return numbers.slice(1).reduce(lcm, numbers[0]);
}

function lcm(a: number, b: number): number {
  return (a * b) / gcd(a, b);
}

function gcdArray(numbers: number[]): number {
  return numbers.slice(1).reduce(gcd, numbers[0]);
}

function gcd(a: number, b: number): number {
  while (b !== 0) {
    const t = b;
    b = a % b;
    a = t;
  }
  return a;
}
