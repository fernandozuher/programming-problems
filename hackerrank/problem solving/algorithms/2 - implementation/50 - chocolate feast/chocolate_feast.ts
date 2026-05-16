// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

function main() {
  for (let i = 0, n = +readLine(); i < n; i++) {
    const [money, cost, wrappersNeeded] = readNumbers();
    console.log(howManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
  }
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(log(money / cost))
// S: O(1) extra space
function howManyChocolatesCanBeEaten(
  money: number,
  cost: number,
  wrappersNeeded: number,
): number {
  let chocolates: number = Math.trunc(money / cost);

  for (let wrappers = chocolates; wrappers >= wrappersNeeded; ) {
    const freeChocolates = Math.trunc(wrappers / wrappersNeeded);
    wrappers = (wrappers % wrappersNeeded) + freeChocolates;
    chocolates += freeChocolates;
  }

  return chocolates;
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
