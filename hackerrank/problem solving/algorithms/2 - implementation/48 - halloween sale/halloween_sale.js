// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

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
  const [price, discount, minPrice, budget] = readNumbers();
  console.log(howManyGamesCanBeBought(price, discount, minPrice, budget));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function howManyGamesCanBeBought(price, discount, minPrice, budget) {
  let count = 0;
  while (budget >= price) {
    count++;
    budget -= price;
    price = Math.max(price - discount, minPrice);
  }
  return count;
}
