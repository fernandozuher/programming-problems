// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

function main() {
  for (let i = 0, n = +readLine(); i < n; i++) {
    const [money, cost, wrappersNeeded] = readNumbers();
    console.log(howManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
  }
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(log(money / cost))
// S: O(1) extra space
function howManyChocolatesCanBeEaten(money, cost, wrappersNeeded) {
  let chocolates = Math.trunc(money / cost);

  for (let wrappers = chocolates; wrappers >= wrappersNeeded; ) {
    const freeChocolates = Math.trunc(wrappers / wrappersNeeded);
    wrappers = (wrappers % wrappersNeeded) + freeChocolates;
    chocolates += freeChocolates;
  }

  return chocolates;
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
