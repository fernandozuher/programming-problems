// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

import { read } from 'morfo';

const n = read(Number);
for (let i = 0; i < n; i++) {
  const prisoners = read(Number);
  const sweets = read(Number);
  const startChair = read(Number);
  console.log(saveThePrisoner(prisoners, sweets, startChair));
}

// T: O(1)
// S: O(1) extra space
function saveThePrisoner(prisoners, sweets, startChair) {
  return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
