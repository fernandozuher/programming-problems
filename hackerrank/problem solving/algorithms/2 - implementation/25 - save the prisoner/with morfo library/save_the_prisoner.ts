// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

import { read } from 'morfo';

const n: number = read(Number);
for (let i = 0; i < n; i++) {
  const prisoners: number = read(Number);
  const sweets: number = read(Number);
  const startChair: number = read(Number);
  console.log(saveThePrisoner(prisoners, sweets, startChair));
}

// T: O(1)
// S: O(1) extra space
function saveThePrisoner(
  prisoners: number,
  sweets: number,
  startChair: number,
): number {
  return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
