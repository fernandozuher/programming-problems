// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

import { readLn, sort } from 'morfo';

const budget = readLn(Number)[0];
const keyboards = preprocessInput(readLn(Number));
const usbDrives = preprocessInput(readLn(Number));
console.log(calcMoneySpent(keyboards, usbDrives, budget));

// n: length of arr
// k: length of arr after deduplication
// k <= n
// T: O(n + k log k)
// S: O(k) extra space
function preprocessInput(arr) {
  return sort([...new Set(arr)]);
}

// n1: length of keyboards
// n2: length of usbDrives
// T: O(n1 + n2)
// S: O(1) extra space
function calcMoneySpent(keyboards, usbDrives, budget) {
  if (keyboards[0] >= budget || usbDrives[0] >= budget) return -1;

  let maxSpent = -1;
  for (
    let idxK = 0, idxUD = usbDrives.length - 1;
    idxK < keyboards.length && idxUD >= 0;
  ) {
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
