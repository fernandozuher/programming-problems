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

////////////////////////////////////////////////

function main() {
  const budget = readNumbers()[0];
  const keyboards = [...new Set(readNumbers())];
  const usbDrives = [...new Set(readNumbers())];
  keyboards.sort((a, b) => a - b);
  usbDrives.sort((a, b) => a - b);
  console.log(calculateMoneySpent(keyboards, usbDrives, budget));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function calculateMoneySpent(keyboards, usbDrives, budget) {
  let maxSpent = -1,
    i = 0,
    j = usbDrives.length - 1;

  while (i < keyboards.length && j >= 0) {
    if (keyboards[i] >= budget) break;

    const sum = keyboards[i] + usbDrives[j];
    if (sum > budget) j--;
    else if (sum == budget) return budget;
    else {
      if (sum > maxSpent) maxSpent = sum;
      i++;
    }
  }

  return maxSpent;
}
