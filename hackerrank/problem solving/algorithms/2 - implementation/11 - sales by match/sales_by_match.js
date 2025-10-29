// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

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
  readLine();
  const sockCounts = readNumbersIntoMap();
  console.log(sockMerchant(sockCounts));
}

function readNumbersIntoMap() {
  const counter = {};
  readLine()
    .split(' ')
    .map(Number)
    .forEach((x) => {
      counter[x] = (counter[x] || 0) + 1;
    });
  return counter;
}

function sockMerchant(sockCounts) {
  return Object.values(sockCounts).reduce(
    (pairs, count) => pairs + Math.trunc(count / 2),
    0,
  );
}
