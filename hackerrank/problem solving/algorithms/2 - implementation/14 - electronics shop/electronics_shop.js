// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
  const budget = readNumbers()[0];
  const keyboards = preprocessInput(readNumbers());
  const usbDrives = preprocessInput(readNumbers());
  console.log(calculateMoneySpent(keyboards, usbDrives, budget));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function preprocessInput(arr) {
  arr = [...new Set(arr)];
  return arr.sort((a, b) => a - b);
}

// n: length of array keyboards
// m: length of array usbDrives
// T: O(n + m)
// S: O(1) extra space
function calculateMoneySpent(keyboards, usbDrives, budget) {
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
