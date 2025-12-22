// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  for (let i = 0, n = +readLine(); i < n; i++) {
    const [money, cost, wrappersNeeded] = readNumbers();
    console.log(howManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
  }
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function howManyChocolatesCanBeEaten(money, cost, wrappersNeeded) {
  let chocolates = Math.trunc(money / cost);

  for (let wrappers = chocolates; wrappers >= wrappersNeeded; ) {
    const freeChocolates = Math.trunc(wrappers / wrappersNeeded);
    wrappers = (wrappers % wrappersNeeded) + freeChocolates;
    chocolates += freeChocolates;
  }

  return chocolates;
}
