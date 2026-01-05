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
  const sockCounts = counter();
  console.log(sockMerchant(sockCounts));
}

function counter() {
  const counter = {};
  readLine()
    .split(' ')
    .forEach((s) => {
      const x = Number(s);
      counter[x] = (counter[x] || 0) + 1;
    });
  return counter;
}

// n: quantity of entries in sockCounts
// T: O(n)
// S: O(1) extra space
function sockMerchant(sockCounts) {
  let pairs = 0;
  for (const key in sockCounts) {
    pairs += Math.trunc(sockCounts[key] / 2);
  }
  return pairs;
}
