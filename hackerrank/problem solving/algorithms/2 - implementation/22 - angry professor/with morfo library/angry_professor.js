// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

import { countIf, read, readLn, skipInput } from 'morfo';

const n = read(Number);
for (let i = 0; i < n; i++) {
  skipInput();
  const threshold = read(Number);
  const arrivalTimes = readLn(Number);
  console.log(angryProfessor(arrivalTimes, threshold) ? 'YES' : 'NO');
}

// k: length of arrivalTimes
// T: O(k)
// S: O(1) extra space
function angryProfessor(arrivalTimes, threshold) {
  const onTime = countIf(arrivalTimes, (t) => t <= 0);
  return onTime < threshold;
}
