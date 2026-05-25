// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

function main() {
  readLine();
  const arr = readNumbers();
  const ratios = plusMinus(arr);
  printRatios(ratios);
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
function plusMinus(arr) {
  let [positive, negative, zero] = [0, 0, 0];

  for (const number of arr)
    if (number > 0) positive++;
    else if (number < 0) negative++;
    else zero++;

  const n = arr.length;
  return [positive / n, negative / n, zero / n];
}

function printRatios(ratios) {
  for (const ratio of ratios) console.log(ratio.toFixed(6));
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
