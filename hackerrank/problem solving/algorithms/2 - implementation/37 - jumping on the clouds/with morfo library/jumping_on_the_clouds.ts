// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

import { readLn, skipInputLn } from 'morfo';

skipInputLn();
console.log(minJumps(readLn(Number)));

// n: length of clouds
// T: O(n)
// S: O(1) extra space
function minJumps(clouds: number[]) {
  let jumps = 0;
  for (let i = 0, n = clouds.length - 1; i < n; i += skip(i, clouds)) jumps++;
  return jumps;
}

function skip(idx: number, clouds: number[]): number {
  return isNextSecondCloudCumulus(idx, clouds) ? 2 : 1;
}

function isNextSecondCloudCumulus(idx: number, clouds: number[]): boolean {
  return idx + 2 < clouds.length && clouds[idx + 2] === 0;
}
