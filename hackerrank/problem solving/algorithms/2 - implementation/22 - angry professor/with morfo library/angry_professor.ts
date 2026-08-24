// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

import { countIf, read, readLn, skipInput } from 'morfo';

const n: number = read(Number);
for (let i = 0; i < n; i++) {
  skipInput();
  const threshold: number = read(Number);
  const arrivalTimes: number[] = readLn(Number);
  console.log(angryProfessor(arrivalTimes, threshold) ? 'YES' : 'NO');
}

// k: length of arrivalTimes
// T: O(k)
// S: O(1) extra space
function angryProfessor(arrivalTimes: number[], threshold: number): boolean {
  const onTime: number = countIf(arrivalTimes, (t) => t <= 0);
  return onTime < threshold;
}
