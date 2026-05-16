// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

function main() {
  const budget = readNumbers()[0];
  const keyboards = preprocessInput(readNumbers());
  const usbDrives = preprocessInput(readNumbers());
  console.log(calcMoneySpent(keyboards, usbDrives, budget));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// k: length of arr after deduplication
// k <= n
// T: O(n + k log k)
// S: O(k) extra space
function preprocessInput(arr) {
  arr = [...new Set(arr)];
  return arr.sort((a, b) => a - b);
}

// n1: length of keyboards
// n2: length of usbDrives
// T: O(n1 + n2)
// S: O(1) extra space
function calcMoneySpent(keyboards, usbDrives, budget) {
  if (keyboards[0] >= budget || usbDrives[0] >= budget) return -1;

  let maxSpent = -1;
  for (let idxK = 0, idxUD = usbDrives.length - 1; idxK < keyboards.length && idxUD >= 0;) {
    if (keyboards[idxK] >= budget) break;

    const currentSum = keyboards[idxK] + usbDrives[idxUD];
    if (currentSum === budget) return budget;

    if (currentSum > budget) idxUD--;
    else {
      maxSpent = Math.max(maxSpent, currentSum);
      idxK++;
    }
  }

  return maxSpent;
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
